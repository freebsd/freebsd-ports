--- cpp/include/IceUtil/Config.h.orig	2019-08-12 19:54:18 UTC
+++ cpp/include/IceUtil/Config.h
@@ -80,13 +80,15 @@
     //
 #   include <stdint.h>
 
-#   if defined(__WORDSIZE) && (__WORDSIZE == 64)
+#   if (__cplusplus >= 201103L) && defined(__WORDSIZE) && (__WORDSIZE == 64)
 #      define ICE_64
-#   elif defined(__WORDSIZE) && (__WORDSIZE == 32)
+#   elif (__cplusplus >= 201103L) && defined(__WORDSIZE) && (__WORDSIZE == 32)
 #      define ICE_32
 #   elif defined(__sun) && (defined(__sparcv9) || defined(__x86_64))  || \
          defined(__linux__) && defined(__x86_64)                      || \
          defined(__APPLE__) && defined(__x86_64)                      || \
+         defined(__FreeBSD__) && defined(__x86_64)                    || \
+         defined(__FreeBSD__) && defined(__LP64__)                    || \
          defined(__hppa) && defined(__LP64__)                         || \
          defined(_ARCH_COM) && defined(__64BIT__)                     || \
          defined(__alpha__)                                           || \
@@ -94,6 +96,16 @@
 #      define ICE_64
 #   else
 #      define ICE_32
+#   endif
+#endif
+
+//
+// FreeBSD 10.0-RELEASE had a broken atexit handler
+// (affects the order of static destruction)
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#   if __FreeBSD_version < 1000700
+#   define ICE_BROKEN_ATEXIT = 1
 #   endif
 #endif
 
