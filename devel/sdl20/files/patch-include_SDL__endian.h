--- include/SDL_endian.h.orig	2020-10-03 02:13:42 UTC
+++ include/SDL_endian.h
@@ -44,6 +44,8 @@
 #define SDL_BYTEORDER  __BYTE_ORDER
 #elif defined(__OpenBSD__)
 #include <endian.h>
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
 #define SDL_BYTEORDER  BYTE_ORDER
 #else
 #if defined(__hppa__) || \
