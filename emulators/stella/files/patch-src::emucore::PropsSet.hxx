--- src/emucore/PropsSet.hxx.orig	Tue Feb 18 10:19:44 2003
+++ src/emucore/PropsSet.hxx	Wed Sep 17 00:47:27 2003
@@ -75,7 +75,7 @@
 
       @param out The output stream to use
     */
-    void save(ostream& out);
+    void save(std::ostream& out);
 
     /**
       Get the number of properties in the collection.
@@ -134,7 +134,7 @@
       @param out The output stream to use
       @param node The current subroot of the tree
     */
-    void saveNode(ostream& out, TreeNode *node);
+    void saveNode(std::ostream& out, TreeNode *node);
 
     // The root of the BST
     TreeNode* myRoot;
