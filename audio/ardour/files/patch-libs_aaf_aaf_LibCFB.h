--- libs/aaf/aaf/LibCFB.h.orig	2023-12-14 15:52:18 UTC
+++ libs/aaf/aaf/LibCFB.h
@@ -28,6 +28,8 @@

 #if defined(__linux__)
 #include <linux/limits.h>
+#elif defined(__FreeBSD__)
+#include <limits.h>
 #elif defined(__APPLE__)
 #include <sys/syslimits.h>
 #elif defined(_MSC_VER) // MSVC
