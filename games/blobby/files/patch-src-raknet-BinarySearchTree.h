--- src/raknet/BinarySearchTree.h.orig	2011-11-10 19:09:02.760002087 +0100
+++ src/raknet/BinarySearchTree.h	2011-11-10 19:16:43.285213671 +0100
@@ -338,12 +338,12 @@
 			if ( current->left == 0 )
 				left_height = 0;
 			else
-				left_height = height( current->left );
+				left_height = this->height( current->left );
 				
 			if ( current->right == 0 )
 				right_height = 0;
 			else
-				right_height = height( current->right );
+				right_height = this->height( current->right );
 				
 			if ( right_height - left_height == 2 )
 			{
@@ -371,7 +371,7 @@
 			if ( current == this->root )
 				break;
 				
-			current = find_parent( *( current->item ) );
+			current = this->find_parent( *( current->item ) );
 			
 		}
 	}
@@ -400,7 +400,7 @@
 		if ( A == 0 )
 			return false;
 			
-		return height( A->right ) > height( A->left );
+		return this->height( A->right ) > this->height( A->left );
 	}
 	
 	template <class BinarySearchTreeType>
@@ -409,7 +409,7 @@
 		if ( A == 0 )
 			return false;
 			
-		return height( A->left ) > height( A->right );
+		return this->height( A->left ) > this->height( A->right );
 	}
 	
 	template <class BinarySearchTreeType>
@@ -446,8 +446,8 @@
 		
 		*/
 		
-		B = find_parent( *( C->item ) );
-		A = find_parent( *( B->item ) );
+		B = this->find_parent( *( C->item ) );
+		A = this->find_parent( *( B->item ) );
 		D = C->right;
 		
 		if ( A )
@@ -510,8 +510,8 @@
 		
 		*/
 		
-		B = find_parent( *( C->item ) );
-		A = find_parent( *( B->item ) );
+		B = this->find_parent( *( C->item ) );
+		A = this->find_parent( *( B->item ) );
 		D = C->left;
 		
 		if ( A )
