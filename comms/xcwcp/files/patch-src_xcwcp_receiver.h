--- src/xcwcp/receiver.h.orig	2018-12-20 17:18:13.332583000 +0100
+++ src/xcwcp/receiver.h	2018-12-20 17:18:39.100884000 +0100
@@ -21,6 +21,9 @@
 
 #include <QMouseEvent>
 #include <QKeyEvent>
+#ifdef __FreeBSD__
+#include <sys/time.h>
+#endif
 
 
 
