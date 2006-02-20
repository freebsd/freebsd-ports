--- class/LKV/AVLTree.h	3 Nov 2004 06:57:51 -0000	1.1
+++ class/LKV/AVLTree.h	3 Nov 2004 11:25:16 -0000	1.3
@@ -26,13 +26,13 @@
 	AVLItem (void) : T()
 #ifdef DEBUG
 	                    , left((AVLItem *)0), right((AVLItem *)0), balance(0)
-#endif DEBUG
+#endif /* DEBUG */
                                                                              { };
 
 	AVLItem (const T & val) : T(val)
 #ifdef DEBUG
 	         , left((AVLItem *)0), right((AVLItem *)0), balance(0)
-#endif DEBUG
+#endif /* DEBUG */
 	        { };
 
 	AVLItem * get_left(void)  const { return left; }
@@ -62,7 +62,7 @@
 	int repair_left  (AVLItem<T> * & aktnode); 
 #ifdef AVL_DEBUG
 	int recurse_check(AVLItem<T> * aktnode, int & cnt);                             
-#endif AVL_DEBUG
+#endif /* AVL_DEBUG */
 	
 public:
 
@@ -76,7 +76,7 @@
 
 #ifdef AVL_DEBUG
 	int check (void) const;
-#endif AVL_DEBUG
+#endif /* AVL_DEBUG */
 
 	AVLItem<T> * find(const T & val) const;
 	AVLItem<T> * find_first(const T & val) const;
@@ -166,7 +166,7 @@
 	return 0;
 }
 
-#endif AVL_DEBUG
+#endif /* AVL_DEBUG */
 
 template <class T>
 void AVLTree<T>::remove(AVLItem<T> * item) {
@@ -576,7 +576,7 @@
 #else
 				recurse_insert( aktnode->left, item,
 				                ext_compare((const T *)item, (const T *)aktnode->left));
-#endif DEBUG
+#endif /* DEBUG */
 			 	return 0;
 			}
 
@@ -621,7 +621,7 @@
 		 				}
 #else
 						recurse_insert( aktnode->left, item, nextcmp);
-#endif DEBUG
+#endif /* DEBUG */
 		 				return 0;
 					} else {
 						// left->right will become aktnode
@@ -684,7 +684,7 @@
 #else
 				recurse_insert( aktnode->right, item, 
 				                ext_compare((const T *)item, (const T *)aktnode->right));
-#endif DEBUG
+#endif /* DEBUG */
 			 	return 0;
 			}
 
@@ -728,7 +728,7 @@
 		 				}
 #else
 						recurse_insert( aktnode->right, item, nextcmp);
-#endif DEBUG
+#endif /* DEBUG */
 		 				return 0;
 					} else {
 						// right->left will become aktnode
@@ -893,9 +893,9 @@
 	return out;
 }
 
-#endif DEBUG
+#endif /* DEBUG */
 
-class BOstream;
+#include "Bstream.h"
 
 template <class T>
 BOstream & operator<< (BOstream & out, const AVLTree<T> & val) {
@@ -910,8 +910,6 @@
 	return out;
 }
 
-class BIstream;
-
 template <class T>
 BIstream & operator>> (BIstream & in, AVLTree<T> & val) {
 
@@ -928,4 +926,4 @@
 }
 
 
-#endif AVLTree_h
+#endif /* AVLTree_h */
