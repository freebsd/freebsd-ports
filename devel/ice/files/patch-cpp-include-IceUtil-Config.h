--- cpp/include/IceUtil/Config.h.orig	2015-06-27 15:37:32.688102665 +0000
+++ cpp/include/IceUtil/Config.h	2015-06-27 15:37:34.926179135 +0000
@@ -49,6 +49,16 @@
 #endif
 
 //
+// FreeBSD 10.0-RELEASE had a broken atexit handler
+// (affects the order of static destruction)
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#   if __FreeBSD_version < 1000700
+#   define ICE_BROKEN_ATEXIT = 1
+#   endif
+#endif
+
+//
 // Check for C++ 11 support
 //
 // For GCC, we recognize --std=c++0x only for GCC version 4.5 and greater,
