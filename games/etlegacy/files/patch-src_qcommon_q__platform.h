--- src/qcommon/q_platform.h.orig	2024-01-16 23:51:21 UTC
+++ src/qcommon/q_platform.h
@@ -264,6 +264,8 @@
 
 #ifdef __i386__
 #define ARCH_STRING "i386"
+#elif defined __aarch64__
+#define ARCH_STRING "aarch64"
 #elif defined __amd64__
 #undef idx64
 #define idx64 1
