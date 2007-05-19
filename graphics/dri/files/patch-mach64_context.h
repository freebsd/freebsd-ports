--- src/mesa/drivers/dri/mach64/mach64_context.h.orig	Mon Nov 28 13:17:16 2005
+++ src/mesa/drivers/dri/mach64/mach64_context.h	Wed Dec 20 15:37:34 2006
@@ -331,25 +331,28 @@
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
-#include <byteswap.h>
-#define LE32_IN( x )		bswap_32( *(GLuint *)(x) )
+#define LE32_IN( x )		CPU_TO_LE32( *(GLuint *)(x) )
 #define LE32_IN_FLOAT( x )						\
 ({									\
-   GLuint __tmp = bswap_32( *(GLuint *)(x) );				\
+   GLuint __tmp = CPU_TO_LE32( *(GLuint *)(x) );			\
    *(GLfloat *)&__tmp;							\
 })
-#define LE32_OUT( x, y )	do { *(GLuint *)(x) = bswap_32( y ); } while (0)
+#define LE32_OUT( x, y )	do { *(GLuint *)(x) = CPU_TO_LE32( y ); } while (0)
+#define LE32_OUT( x, y )						\
+do {									\
+   *(GLuint *)(x) = CPU_TO_LE32( y );					\
+} while (0)
 #define LE32_OUT_FLOAT( x, y )						\
 do {									\
    GLuint __tmp;							\
    *(GLfloat *)&__tmp = (y);						\
-   *(GLuint *)(x) = bswap_32( __tmp );					\
+   *(GLuint *)(x) = CPU_TO_LE32( __tmp );				\
 } while (0)
 #endif
 
