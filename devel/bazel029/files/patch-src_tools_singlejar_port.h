--- src/tools/singlejar/port.h.orig	2018-09-18 16:02:23.430634000 +0200
+++ src/tools/singlejar/port.h	2018-09-18 16:03:58.961047000 +0200
@@ -28,6 +28,11 @@
 #include <sys/types.h>
 #include <time.h>
 
+#ifndef _OFF64_T_DECLARED
+typedef off_t off64_t;
+#define _OFF64_T_DECLARED
+#endif
+
 #if defined(__APPLE__)
 typedef off_t off64_t;
 #elif defined(_WIN32)
