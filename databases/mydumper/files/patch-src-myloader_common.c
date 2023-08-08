--- src/myloader_common.c.orig	2023-05-24 12:16:48 UTC
+++ src/myloader_common.c
@@ -21,6 +21,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/wait.h>
+#include <unistd.h>
 
 #ifdef ZWRAP_USE_ZSTD
 #include "../zstd/zstd_zlibwrapper.h"
