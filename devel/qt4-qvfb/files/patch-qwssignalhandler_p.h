--- qwssignalhandler_p.h.orig	Sun Jan 14 15:52:43 2007
+++ qwssignalhandler_p.h	Sun Jan 14 15:52:57 2007
@@ -39,6 +39,8 @@
 #include <QtCore/qvector.h>
 #include <signal.h>
 
+typedef void (*sighandler_t)(int);
+
 class QWSSignalHandler
 {
 public:
