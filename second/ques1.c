//Create a singly linked list inserting an element in the beginning and display the elements.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * head;

void createList(int number);
void printList();

int main()
{
    int numberOfNodes;
    printf("Enter the total number of nodes: \n");
    scanf("%d", &numberOfNodes);

    createList(numberOfNodes);

    printf("Data in list \n");
    printList();
    return 0;
}

void createList(int number)
{
    struct node *newNode, *temp;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        printf("Unable to allocate the memory \n");
        exit(0);
    }

    printf("Enter the data for node 1: ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;

    temp = head;
    for (i = 2; i <= number; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        if (newNode == NULL)
        {
            printf("Unable to allocate memory");
            break;
        }

        printf("Enter the data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        temp->next = newNode;
        temp = temp->next;
    }
}

void printList()
{
    struct node *temp;
    int i = 1;
    if (head == NULL)
    {
        printf("List is empty");
    }
    temp = head;
    while (temp != NULL)
    {
        printf("Data in %d id %d \n", i, temp->data);
        temp = temp->next;
        i++;
    }
}