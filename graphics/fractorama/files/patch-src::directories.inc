--- directories.inc.orig	Mon Apr  9 03:09:39 2001
+++ directories.inc	Sun Apr 15 16:46:55 2001
@@ -4,4 +4,4 @@
 
 WINDOWS_QTROOT     := e:/qt
 WINDOWS_VC_INCLUDE := e:/devstudio/vc/include
-UNIX_QTROOT        := /tools/qt-2.3.0
+UNIX_QTROOT        := ${X11BASE}
