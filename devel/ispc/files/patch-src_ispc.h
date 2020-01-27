--- src/ispc.h.orig	2020-01-25 02:15:35 UTC
+++ src/ispc.h
@@ -49,6 +49,8 @@
 #define ISPC_HOST_IS_WINDOWS
 #elif defined(__linux__)
 #define ISPC_HOST_IS_LINUX
+#elif defined(__FreeBSD__)
+#define ISPC_HOST_FREEBSD
 #elif defined(__APPLE__)
 #define ISPC_HOST_IS_APPLE
 #endif
