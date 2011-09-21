--- src/gallium/include/pipe/p_config.h.orig	2011-09-21 14:41:38.000000000 +0200
+++ src/gallium/include/pipe/p_config.h	2011-09-21 14:42:54.000000000 +0200
@@ -113,6 +113,7 @@
 
 #ifdef __GLIBC__
 #include <endian.h>
+#error GLIBC
 
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 # define PIPE_ARCH_LITTLE_ENDIAN
@@ -120,15 +121,16 @@
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
 
+
 #else
 
 #if defined(PIPE_ARCH_X86) || defined(PIPE_ARCH_X86_64)
