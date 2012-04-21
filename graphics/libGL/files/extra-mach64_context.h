--- src/mesa/drivers/dri/mach64/mach64_context.h.orig	2011-05-13 01:47:18.000000000 +0200
+++ src/mesa/drivers/dri/mach64/mach64_context.h	2011-07-27 09:59:53.000000000 +0200
@@ -289,7 +289,7 @@
 /* ================================================================
  * Byte ordering
  */
-#if MESA_LITTLE_ENDIAN == 1
+#if defined(MESA_LITTLE_ENDIAN) && MESA_LITTLE_ENDIAN == 1
 #define LE32_IN( x )		( *(GLuint *)(x) )
 #define LE32_IN_FLOAT( x )	( *(GLfloat *)(x) )
 #define LE32_OUT( x, y )	do { *(GLuint *)(x) = (y); } while (0)
@@ -298,6 +298,9 @@
 #if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <machine/endian.h>
 #define bswap_32 bswap32
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define bswap_32 bswap32
 #else
 #include <byteswap.h>
 #endif
