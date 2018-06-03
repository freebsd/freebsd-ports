--- src/FileIO.cpp.orig	2015-01-02 18:01:46 UTC
+++ src/FileIO.cpp
@@ -1617,7 +1617,7 @@ Project* FileIO::importFile(Import* imp, ScrollView* s
   QString ext;
 
   if (!imp)
-    return FALSE;
+    return NULL;
 
   Project* p=NULL;
   importdlg->setAcceptMode(QFileDialog::AcceptOpen);
@@ -1641,7 +1641,7 @@ Project* FileIO::importFile(Import* imp, ScrollView* s
   ifstream fin(act_importfile);
 
   if (!fin)
-    return FALSE;
+    return NULL;
 
   emit setWaitCursor();
 
