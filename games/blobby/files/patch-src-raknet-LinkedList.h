--- src/raknet/LinkedList.h.orig	2024-11-12 08:04:07 UTC
+++ src/raknet/LinkedList.h
@@ -463,6 +463,7 @@ namespace BasicDataStructures
 		CircularLinkedList<CircularLinkedListType>::CircularLinkedList( const CircularLinkedList& original_copy )
 	{
 		node * original_copy_pointer;
+		node *last;
 		node *save_position;
 
 		if ( original_copy.list_size == 0 )
@@ -504,7 +505,7 @@ namespace BasicDataStructures
 
 
 					// Save the current element
-					this->last = this->position;
+					last = this->position;
 
 					// Point to the next node in the source list
 					original_copy_pointer = original_copy_pointer->next;
@@ -521,10 +522,10 @@ namespace BasicDataStructures
 						save_position = position;
 
 					// Set the previous pointer for the new node
-					( this->position->previous ) = this->last;
+					( this->position->previous ) = last;
 
 					// Set the next pointer for the old node to the new node
-					( this->last->next ) = this->position;
+					( last->next ) = this->position;
 
 				}
 
@@ -545,6 +546,7 @@ namespace BasicDataStructures
 		bool CircularLinkedList<CircularLinkedListType>::operator= ( const CircularLinkedList& original_copy )
 	{
 		node * original_copy_pointer;
+		node *last;
 		node *save_position;
 
 		if ( ( &original_copy ) != this )
@@ -589,7 +591,7 @@ namespace BasicDataStructures
 					do
 					{
 						// Save the current element
-						this->last = this->position;
+						last = this->position;
 
 						// Point to the next node in the source list
 						original_copy_pointer = original_copy_pointer->next;
@@ -606,10 +608,10 @@ namespace BasicDataStructures
 							save_position = this->position;
 
 						// Set the previous pointer for the new node
-						( this->position->previous ) = this->last;
+						( this->position->previous ) = last;
 
 						// Set the next pointer for the old node to the new node
-						( this->last->next ) = this->position;
+						( last->next ) = this->position;
 
 					}
 
