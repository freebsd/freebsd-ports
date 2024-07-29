--- ui/zenoedit/zenomainwindow.cpp.orig	2024-04-22 13:07:02 UTC
+++ ui/zenoedit/zenomainwindow.cpp
@@ -1467,7 +1467,7 @@ void ZenoMainWindow::onZenovisFrameUpdate(bool bGLView
 
 void ZenoMainWindow::onCheckUpdate()
 {
-#ifdef __linux__
+#if defined( __linux__) || defined(__FreeBSD__)
     return;
 #else
     ZCheckUpdateDlg dlg(this);
