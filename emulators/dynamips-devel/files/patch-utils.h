--- utils.h.orig	Fri Feb 24 06:59:58 2006
+++ utils.h	Fri Feb 24 07:00:14 2006
@@ -34,6 +34,8 @@
 #define ARCH_BYTE_ORDER ARCH_LITTLE_ENDIAN
 #elif defined(__x86_64__)
 #define ARCH_BYTE_ORDER ARCH_LITTLE_ENDIAN
+#elif defined(__ia64__)
+#define ARCH_BYTE_ORDER ARCH_LITTLE_ENDIAN
 #endif
 
 #ifndef ARCH_BYTE_ORDER
