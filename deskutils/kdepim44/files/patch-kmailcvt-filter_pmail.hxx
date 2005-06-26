Index: filter_pmail.hxx
===================================================================
--- kmailcvt/filter_pmail.hxx	(revision 427509)
+++ kmailcvt/filter_pmail.hxx	(working copy)
@@ -50,8 +50,12 @@
     QDir dir;
     /**  pointer to the info */
     FilterInfo * inf;
-    /** QStringList with the foldernames, First String contains the ID, the second the folder */
-    QValueList<QString[5]> folderMatrix;
+
+    /** Folder structure here has 5 entries. */
+    typedef FolderStructureBase<5> FolderStructure;
+    /** List with the foldernames, First String contains the ID, the second the folder. Rest have no semantics at all but are essential anyway. */
+    QValueList<FolderStructure> folderMatrix;
+    typedef QValueList<FolderStructure>::Iterator FolderStructureIterator;
     
     bool folderParsed;
     