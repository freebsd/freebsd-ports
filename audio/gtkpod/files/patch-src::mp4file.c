--- src/mp4file.c.orig	Wed Jul 28 00:22:05 2004
+++ src/mp4file.c	Wed Jul 28 00:22:50 2004
@@ -108,7 +108,8 @@
 #define MP4V2_HAS_METADATA_BUG TRUE
 
 #include <sys/types.h>
-#include <stdint.h>
+#include <sys/param.h>
+#include <inttypes.h>
 #include <stdlib.h>
 #include <string.h>
 #include "mp4.h"
