// C program to demonstrate insert operation in binary search tree using recursion.
#include<stdio.h>
#include<stdlib.h>

struct node
{
 int key;
 struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int value)
{
 struct node *temp = (struct node *)malloc(sizeof(struct node));
 temp->key = value;
 temp->left = temp->right = NULL;
 return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
 if (root != NULL)
 {
  inorder(root->left);
  printf("%d \n", root->key);
  inorder(root->right);
 }
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
 /* If the tree is empty, return a new node */
 if (node == NULL) return newNode(key);

 /* Otherwise, recur down the tree */
 if (key < node->key)
  node->left = insert(node->left, key);

 else if (key > node->key)
  node->right = insert(node->right, key);

 /* return the (unchanged) node pointer */
 return node;
}

// Driver Function
int main()
{
 struct node *root = NULL;
 int i, arr[] = { 10, 20, 30, 40, 50, 60, 70 };
 root = insert(root, 50);
 for( i = 0 ; i < sizeof(arr)/sizeof(int); i++)
  insert(root, 30);

 inorder(root);
 return 0;
}
