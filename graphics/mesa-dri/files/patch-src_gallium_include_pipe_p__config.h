--- src/gallium/include/pipe/p_config.h.orig	2019-06-26 20:14:08 UTC
+++ src/gallium/include/pipe/p_config.h
@@ -160,6 +160,12 @@
 #define PIPE_OS_ANDROID
 #endif
 
+#if defined(__DragonFly__)
+#define PIPE_OS_DRAGONFLY
+#define PIPE_OS_BSD
+#define PIPE_OS_UNIX
+#endif
+
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 #define PIPE_OS_FREEBSD
 #define PIPE_OS_BSD
