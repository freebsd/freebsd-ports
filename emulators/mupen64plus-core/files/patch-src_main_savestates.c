--- src/main/savestates.c.orig	2026-11-11 22:45:05 UTC
+++ src/main/savestates.c
@@ -31,8 +31,8 @@
 #include <string.h>
 #include <sys/types.h>
 #include <zlib.h>
-#include <unzip.h>
-#include <zip.h>
+#include <minizip/unzip.h>
+#include <minizip/zip.h>
 
 #define M64P_CORE_PROTOTYPES 1
 #include "api/callbacks.h"
