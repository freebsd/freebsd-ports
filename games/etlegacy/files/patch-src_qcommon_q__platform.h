--- src/qcommon/q_platform.h.orig	2026-08-02 10:13:43 UTC
+++ src/qcommon/q_platform.h
@@ -278,6 +278,16 @@
 #define ARCH_STRING "x86_64"
 #elif defined __axp__
 #define ARCH_STRING "alpha"
+#elif defined __powerpc64__
+#if BYTE_ORDER == BIG_ENDIAN
+#define ARCH_STRING "powerpc64"
+#else
+#define ARCH_STRING "powerpc64le"
+#endif
+#elif defined __powerpc__
+#define ARCH_STRING "powerpc"
+#elif defined __arm__
+#define ARCH_STRING "armv7"
 #endif
 
 #if BYTE_ORDER == BIG_ENDIAN
