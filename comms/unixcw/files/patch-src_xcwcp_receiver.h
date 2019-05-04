--- src/xcwcp/receiver.h.orig	2018-12-20 16:18:13 UTC
+++ src/xcwcp/receiver.h
@@ -21,6 +21,9 @@
 
 #include <QMouseEvent>
 #include <QKeyEvent>
+#ifdef __FreeBSD__
+#include <sys/time.h>
+#endif
 
 
 
