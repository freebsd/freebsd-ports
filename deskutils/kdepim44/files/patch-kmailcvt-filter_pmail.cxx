Index: filter_pmail.cxx
===================================================================
--- kmailcvt/filter_pmail.cxx	(revision 427509)
+++ kmailcvt/filter_pmail.cxx	(working copy)
@@ -325,8 +325,8 @@
     
     while (!found)
     {
-        for ( QValueList<QString[5]>::Iterator it = folderMatrix.begin(); it != folderMatrix.end(); it++) {
-            QString tmp[5] = *it;
+        for ( FolderStructureIterator it = folderMatrix.begin(); it != folderMatrix.end(); it++) {
+            FolderStructure tmp = *it;
             
             QString _ID = tmp[2];
             if(_ID == search) {