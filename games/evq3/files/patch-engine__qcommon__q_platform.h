--- ./engine/qcommon/q_platform.h.orig	Sat Dec 16 17:45:12 2006
+++ ./engine/qcommon/q_platform.h	Sun Apr 22 17:08:47 2007
@@ -178,8 +178,14 @@
 
 #ifdef __i386__
 #define ARCH_STRING "i386"
-#elif defined __axp__
+#elif defined __alpha__
 #define ARCH_STRING "alpha"
+#elif defined __amd64__
+#define ARCH_STRING "amd64"
+#elif defined __sparc64__
+#define ARCH_STRING "sparc64"
+#else
+#define ARCH_STRING "unknown"
 #endif
 
 #if BYTE_ORDER == BIG_ENDIAN
