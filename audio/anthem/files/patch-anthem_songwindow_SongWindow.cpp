--- anthem/songwindow/SongWindow.cpp.orig	Thu May 27 22:16:01 2004
+++ anthem/songwindow/SongWindow.cpp	Thu May 27 22:14:48 2004
@@ -853,7 +853,7 @@
 
 void SongWindow::slotRevert()
 {
-    if (filename && modified.modified())
+    if (!filename.isEmpty() && modified.modified())
     {
         if (messageBoxSave())
         {
