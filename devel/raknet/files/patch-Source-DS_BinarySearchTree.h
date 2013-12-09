--- Source/DS_BinarySearchTree.h.orig	2013-11-15 22:00:44.000000000 +0100
+++ Source/DS_BinarySearchTree.h	2013-11-15 22:02:47.000000000 +0100
@@ -166,12 +166,12 @@
 			if ( current->left == 0 )
 				left_height = 0;
 			else
-				left_height = Height( current->left );
+				left_height = this->Height( current->left );
 				
 			if ( current->right == 0 )
 				right_height = 0;
 			else
-				right_height = Height( current->right );
+				right_height = this->Height( current->right );
 				
 			if ( right_height - left_height == 2 )
 			{
@@ -199,7 +199,7 @@
 			if ( current == this->root )
 				break;
 				
-			current = FindParent( *( current->item ) );
+			current = this->FindParent( *( current->item ) );
 			
 		}
 	}
@@ -226,7 +226,7 @@
 		if ( A == 0 )
 			return false;
 			
-		return Height( A->right ) > Height( A->left );
+		return this->Height( A->right ) > this->Height( A->left );
 	}
 	
 	template <class BinarySearchTreeType>
@@ -235,7 +235,7 @@
 		if ( A == 0 )
 			return false;
 			
-		return Height( A->left ) > Height( A->right );
+		return this->Height( A->left ) > this->Height( A->right );
 	}
 	
 	template <class BinarySearchTreeType>
@@ -272,8 +272,8 @@
 		
 		*/
 		
-		B = FindParent( *( C->item ) );
-		A = FindParent( *( B->item ) );
+		B = this->FindParent( *( C->item ) );
+		A = this->FindParent( *( B->item ) );
 		D = C->right;
 		
 		if ( A )
@@ -336,8 +336,8 @@
 		
 		*/
 		
-		B = FindParent( *( C->item ) );
-		A = FindParent( *( B->item ) );
+		B = this->FindParent( *( C->item ) );
+		A = this->FindParent( *( B->item ) );
 		D = C->left;
 		
 		if ( A )
