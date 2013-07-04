Disable grey welcome screen as it crashes Notecase at startup

--- src/MainWnd.cpp.orig	2013-07-03 17:46:48.000000000 +0200
+++ src/MainWnd.cpp	2013-07-03 17:46:48.000000000 +0200
@@ -147,7 +147,7 @@
 {
 	g_shortcuts.Load();
 
-	g_objIni.GetValue("Display", "DrawGrayTextView", g_bDrawTextviewExpose, 1);
+	g_objIni.GetValue("Display", "DrawGrayTextView", g_bDrawTextviewExpose, 0);
 
 	g_objIni.GetValue("Display", "TreeToTheRight", g_bTreeToTheRight);
 	g_bTreeToTheRightInitial = g_bTreeToTheRight;
