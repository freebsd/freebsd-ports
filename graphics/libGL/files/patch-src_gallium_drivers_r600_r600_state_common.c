--- src/gallium/drivers/r600/r600_state_common.c.orig	2013-03-06 00:25:39.000000000 +0100
+++ src/gallium/drivers/r600/r600_state_common.c	2013-06-26 23:26:02.000000000 +0200
@@ -33,7 +33,12 @@
 #include "util/u_memory.h"
 #include "util/u_upload_mgr.h"
 #include "tgsi/tgsi_parse.h"
+#if defined(__linux__)
 #include <byteswap.h>
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define bswap_32(x)	bswap32((x))
+#endif
 
 #define R600_PRIM_RECTANGLE_LIST PIPE_PRIM_MAX
 
