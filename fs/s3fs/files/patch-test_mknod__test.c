--- test/mknod_test.c.orig	2023-05-21 23:25:50 UTC
+++ test/mknod_test.c
@@ -28,7 +28,10 @@
 #include <string.h>
 #include <errno.h>
 #ifndef __APPLE__
+#elif
+#ifndef __FreeBSD__
 #include <sys/sysmacros.h>
+#endif
 #endif
 
 //---------------------------------------------------------
