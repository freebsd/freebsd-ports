--- src/openhbci/tree.h.orig	Mon Jan  3 23:31:35 2005
+++ src/openhbci/tree.h	Mon Jan  3 23:28:50 2005
@@ -695,16 +695,16 @@
    * Returns an iterator that points to the root of the tree.
    * @author Martin Preuss<martin@aquamaniac.de>
    */
-  Tree<T>::iterator root() {
-      return Tree<T>::iterator(&_root);
+  iterator root() {
+      return iterator(&_root);
   };
 
   /**
    * Returns an const_iterator that points to the root of the tree.
    * @author Martin Preuss<martin@aquamaniac.de>
    */
-  Tree<T>::const_iterator const_root() const {
-      return Tree<T>::const_iterator(&_root);
+  const_iterator const_root() const {
+      return const_iterator(&_root);
   };
 
   /**
