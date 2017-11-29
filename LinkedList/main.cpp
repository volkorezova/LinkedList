//
//  main.cpp
//  LinkedList
//
//  Created by Tatyana Volkorezova on 26.11.2017.
//  Copyright © 2017 shpp.com. All rights reserved.
//

#include <iostream>
using namespace std;

class Node{
public:
    Node* nextNode;
    Node* prevNode;
    int value;
    
    Node(int value){
        this->value = value;
        nextNode = nullptr;
        prevNode = nullptr;
    }
};


class LinkedList{
public:
    Node* firstNode = nullptr;
    Node* lastNode = nullptr;
    Node* currentNode = nullptr;
    Node* prevNode = nullptr;
    int sizeOfList;
    
    void add(int value);
    void showNode(Node* node);
    void removeNode(int pos);
    void get(int pos);
    void addNode(int value, int index);
    
};



//method for adding new elements to the list one after another
void LinkedList::add(int value){
    Node* tmpNode = new Node(value);
    
    //add to the head (the first elemet)
    if(firstNode == nullptr){
        firstNode = tmpNode;
        lastNode = tmpNode;
        tmpNode = nullptr;
        
        //add to the end of list
    }else{
        lastNode->nextNode = tmpNode;
        tmpNode->nextNode = nullptr;
        lastNode = tmpNode;
    }
    sizeOfList++;
}

//method for displaying of list
void LinkedList::showNode(Node* node){
    cout<<node->value<<endl;
    if (node->nextNode != nullptr){
        showNode (node->nextNode);
    }
}

//method which remove node via mentioned position
void LinkedList::removeNode(int index)
{
    //case when position out of bound
    if (index < 0 || index > sizeOfList){
        cout<< "ERROR! OUT OF BOUND!"<<endl;
        return;
    }
    //delete the first node
    if (index == 0){
        Node *temp = firstNode;
        firstNode = firstNode->nextNode;
        delete temp;
    }
    //delete last node
    else if (index == sizeOfList){
        currentNode = firstNode;
        
        while(currentNode->nextNode != nullptr){
            prevNode = currentNode;
            currentNode = currentNode->nextNode;
        }
        lastNode = prevNode;
        prevNode->nextNode = nullptr;
        delete currentNode;
    }else{
        //delete other nodes (any position)
        currentNode = firstNode;
        for(int i=1;i<index;i++){
            prevNode=currentNode;
            currentNode=currentNode->nextNode;
        }
        prevNode->nextNode=currentNode->nextNode;
    }
}

//method for getting value via selecte position of linked list
void LinkedList::get(int index) {
    if (index < 0 || index > sizeOfList) {
        cout<<"ERROR! OUT OF BOUND!"<<endl;
        return;
    }
    Node *tmpNode = firstNode;
    for (int i = 0; i < index; i++){
        tmpNode = tmpNode->nextNode;
    }
    cout<<"Get value from position "<<index<<":"<<tmpNode->value<<endl;
}

//method for inserting node by index
void LinkedList::addNode(int value, int index){
    
    if (index < 0 || index > sizeOfList) {
        cout << "ERROR! OUT OF BOUND" << endl;
        return;
    }
    Node* tmpNode = new Node(value);
    
    //insert to head
    if(index == 0){
        tmpNode->nextNode = firstNode;
        firstNode = tmpNode;
        return;
    }
    //insert to the end of list
    else if (index == sizeOfList){
        lastNode->nextNode = tmpNode;
        lastNode = tmpNode;
        return;
    }else{
        //insert to selected index
        currentNode = firstNode;
        for(int i=0;i<index;i++){
            prevNode=currentNode;
            currentNode=currentNode->nextNode;
        }
        tmpNode->value=value;
        prevNode->nextNode=tmpNode;
        tmpNode->nextNode=currentNode;
    }
    sizeOfList++;
}

int main(int argc, const char * argv[]) {
    LinkedList l;
    l.add(12);
    l.add(13);
    l.add(67);
    l.add(623);
    l.add(1);
    l.add(99);
    l.add(0);
    
    l.showNode(l.firstNode);
    cout<<endl;
    
    l.removeNode(0);
    l.showNode(l.firstNode);
    
    l.removeNode(6);
    l.removeNode(4);
    cout<<endl;
    l.showNode(l.firstNode);
    
    l.get(2);
    l.addNode(3, 0);
    cout<<endl;
    l.showNode(l.firstNode);
    return 0;
}
