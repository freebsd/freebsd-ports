--- src/gallium/drivers/r600/r600_asm.c.orig	2013-03-20 00:28:25.000000000 +0100
+++ src/gallium/drivers/r600/r600_asm.c	2013-06-26 23:29:14.000000000 +0200
@@ -27,7 +27,12 @@
 #include "r600d.h"
 
 #include <errno.h>
+#if defined(__linux__)
 #include <byteswap.h>
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define bswap_32(x)	bswap32((x))
+#endif
 #include "util/u_memory.h"
 #include "pipe/p_shader_tokens.h"
 
