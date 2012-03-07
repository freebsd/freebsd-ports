--- src/gallium/include/pipe/p_config.h.orig	2012-03-06 13:42:46.000000000 +0100
+++ src/gallium/include/pipe/p_config.h	2012-03-06 13:43:21.000000000 +0100
@@ -120,12 +120,12 @@
 # define PIPE_ARCH_BIG_ENDIAN
 #endif
 
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 #include <machine/endian.h>
 
-#if __DARWIN_BYTE_ORDER == __DARWIN_LITTLE_ENDIAN
+#if __DARWIN_BYTE_ORDER == __DARWIN_LITTLE_ENDIAN || _BYTE_ORDER == _LITTLE_ENDIAN
 # define PIPE_ARCH_LITTLE_ENDIAN
-#elif __DARWIN_BYTE_ORDER == __DARWIN_BIG_ENDIAN
+#elif __DARWIN_BYTE_ORDER == __DARWIN_BIG_ENDIAN || _BYTE_ORDER == _BIG_ENDIAN
 # define PIPE_ARCH_BIG_ENDIAN
 #endif
 
