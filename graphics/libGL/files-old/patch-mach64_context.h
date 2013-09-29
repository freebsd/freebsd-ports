--- src/mesa/drivers/dri/mach64/mach64_context.h.orig	2012-06-27 19:59:32.000000000 +0200
+++ src/mesa/drivers/dri/mach64/mach64_context.h	2012-06-27 20:08:30.000000000 +0200
@@ -294,11 +294,14 @@
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
