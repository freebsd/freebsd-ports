--- src/vid_voodoo_render.c.orig	2020-12-01 19:49:05 UTC
+++ src/vid_voodoo_render.c
@@ -1,5 +1,8 @@
 #include <math.h>
 #include <stddef.h>
+#ifdef __FreeBSD__
+#include <sys/mman.h>
+#endif
 #include "ibm.h"
 #include "device.h"
 #include "mem.h"
