--- lib/video/renderer.cpp.orig	Tue Aug 28 22:53:20 2001
+++ lib/video/renderer.cpp	Tue Aug 28 22:53:30 2001
@@ -20,6 +20,7 @@
 #include <fcntl.h>
 #include <sys/ioctl.h>
 #include <sys/time.h>
+#include <pthread.h>
 
 #ifndef WITHOUT_X
 
