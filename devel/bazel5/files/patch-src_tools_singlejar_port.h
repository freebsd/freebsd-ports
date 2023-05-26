--- src/tools/singlejar/port.h.orig	1979-12-31 23:00:00 UTC
+++ src/tools/singlejar/port.h
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
