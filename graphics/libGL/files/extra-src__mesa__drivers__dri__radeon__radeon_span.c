--- src/mesa/drivers/dri/radeon/radeon_span.c.orig	2011-07-09 03:37:10.000000000 +0200
+++ src/mesa/drivers/dri/radeon/radeon_span.c	2012-06-28 21:44:07.000000000 +0200
@@ -55,7 +55,11 @@
 #include <byteswap.h>
 #define CPU_TO_LE16( x )	bswap_16( x )
 #define LE16_TO_CPU( x )	bswap_16( x )
-#endif /* __linux__ */
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define CPU_TO_LE16( x )	bswap16( x )
+#define LE16_TO_CPU( x )	bswap16( x )
+#endif
 #else
 #define CPU_TO_LE16( x )	( x )
 #define LE16_TO_CPU( x )	( x )
