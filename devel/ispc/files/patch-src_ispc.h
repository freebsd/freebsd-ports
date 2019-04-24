--- src/ispc.h.orig	2019-04-20 16:38:55 UTC
+++ src/ispc.h
@@ -48,6 +48,8 @@
 #define ISPC_IS_WINDOWS
 #elif defined(__linux__)
 #define ISPC_IS_LINUX
+#elif defined(__FreeBSD__)
+#define ISPC_IS_FREEBSD
 #elif defined(__APPLE__)
 #define ISPC_IS_APPLE
 #endif
