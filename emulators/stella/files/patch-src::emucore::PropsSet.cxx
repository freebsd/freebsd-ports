--- src/emucore/PropsSet.cxx.orig	Tue Feb 18 10:19:44 2003
+++ src/emucore/PropsSet.cxx	Wed Sep 17 00:47:25 2003
@@ -203,14 +203,14 @@
 }
 
 // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
-void PropertiesSet::save(ostream& out)
+void PropertiesSet::save(std::ostream& out)
 {
   saveNode(out, myRoot);
 }
 
 
 // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
-void PropertiesSet::saveNode(ostream& out, TreeNode *node)
+void PropertiesSet::saveNode(std::ostream& out, TreeNode *node)
 {
   if(node)
   {
