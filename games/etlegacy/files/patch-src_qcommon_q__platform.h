--- src/qcommon/q_platform.h.orig	2023-03-12 18:33:03 UTC
+++ src/qcommon/q_platform.h
@@ -264,12 +264,20 @@
 
 #ifdef __i386__
 #define ARCH_STRING "i386"
+#elif defined __aarch64__
+#define ARCH_STRING "aarch64"
 #elif defined __amd64__
 #undef idx64
 #define idx64 1
 #define ARCH_STRING "x86_64"
 #elif defined __axp__
 #define ARCH_STRING "alpha"
+#elif defined __powerpc64__
+#define ARCH_STRING "ppc64"
+#elif defined __powerpc__
+#define ARCH_STRING "ppc"
+#elif defined __arm__
+#define ARCH_STRING "arm" // __ARM_ARCH_'V'__ FIXME: add ARM version to the ARCH_STRING
 #endif
 
 #if BYTE_ORDER == BIG_ENDIAN
