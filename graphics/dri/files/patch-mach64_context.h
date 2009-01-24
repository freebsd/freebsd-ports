--- src/mesa/drivers/dri/mach64/mach64_context.h.orig	2009-01-21 10:55:48.000000000 -0500
+++ src/mesa/drivers/dri/mach64/mach64_context.h	2009-01-22 13:48:00.000000000 -0500
@@ -288,17 +288,20 @@
 /* ================================================================
  * Byte ordering
  */
-#if MESA_LITTLE_ENDIAN == 1
+#if defined(MESA_LITTLE_ENDIAN) && MESA_LITTLE_ENDIAN == 1
 #define LE32_IN( x )		( *(GLuint *)(x) )
 #define LE32_IN_FLOAT( x )	( *(GLfloat *)(x) )
 #define LE32_OUT( x, y )	do { *(GLuint *)(x) = (y); } while (0)
 #define LE32_OUT_FLOAT( x, y )	do { *(GLfloat *)(x) = (y); } while (0)
 #else
-#ifndef __OpenBSD__
-#include <byteswap.h>
-#else
+#if defined(__OpenBSD__)
 #include <machine/endian.h>
 #define bswap_32 bswap32
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define bswap_32 bswap32
+#else
+#include <byteswap.h>
 #endif
 
 #define LE32_IN( x )		bswap_32( *(GLuint *)(x) )
