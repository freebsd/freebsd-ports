--- ui/zenoedit/zenomainwindow.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/zenomainwindow.cpp
@@ -1479,7 +1479,7 @@ void ZenoMainWindow::onCheckUpdate()
 
 void ZenoMainWindow::onCheckUpdate()
 {
-#ifdef __linux__
+#if defined( __linux__) || defined(__FreeBSD__)
     return;
 #else
     ZCheckUpdateDlg dlg(this);
