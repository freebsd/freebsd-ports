--- src/lib/index/index_read.c.orig	2020-09-25 20:29:27 UTC
+++ src/lib/index/index_read.c
@@ -28,7 +28,11 @@
 #include <stdint.h>
 #include <stdbool.h>
 #include <string.h>
+#if !defined(__FreeBSD__)
 #include <endian.h>
+#else
+#include <sys/endian.h>
+#endif
 #include <zck.h>
 
 #include "zck_private.h"
