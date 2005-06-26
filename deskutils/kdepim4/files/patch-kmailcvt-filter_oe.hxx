Index: filter_oe.hxx
===================================================================
--- kmailcvt/filter_oe.hxx	(revision 427509)
+++ kmailcvt/filter_oe.hxx	(working copy)
@@ -63,8 +63,12 @@
     bool parsedFolder;
     /** true if the current parsing file is the folder file */
     bool currentIsFolderFile;
+
+    /** Folder structure here has 4 entries. */
+    typedef FolderStructureBase<4> FolderStructure;
     /** matrix with information about the folder structure*/
-    QValueList<QString[4]> folderStructure;
+    QValueList<FolderStructure> folderStructure;
+    typedef QValueList<FolderStructure>::Iterator FolderStructureIterator;
 
     /** name of the current folder */
     QString folderName;
