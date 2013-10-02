--- src/fqterm/fqterm_wndmgr.cpp.orig	2013-10-02 06:06:59.000000000 +0000
+++ src/fqterm/fqterm_wndmgr.cpp
@@ -53,7 +53,7 @@ int FQTermWndMgr::addWindow(FQTermWindow
 
   Q_ASSERT(mw != NULL);
   termWindows_.append(mw);
-  Q_ASSERT(qtab != QString::QString());
+  Q_ASSERT(qtab != QString());
   tabCaptions_.append(qtab);
   icons_.append(icon);
 
