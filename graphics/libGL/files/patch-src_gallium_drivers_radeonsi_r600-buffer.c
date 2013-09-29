--- src/gallium/drivers/radeonsi/r600_buffer.c.orig	2013-08-01 00:56:45.000000000 +0200
+++ src/gallium/drivers/radeonsi/r600_buffer.c	2013-08-19 21:36:02.000000000 +0200
@@ -24,7 +24,13 @@
  *      Jerome Glisse
  *      Corbin Simpson <MostAwesomeDude@gmail.com>
  */
+
+#if defined(__linux__)
 #include <byteswap.h>
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define bswap_32(x)	bswap32((x))
+#endif
 
 #include "pipe/p_screen.h"
 #include "util/u_format.h"
