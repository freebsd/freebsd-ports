--- src/files.c.orig	2023-05-17 05:45:51 UTC
+++ src/files.c
@@ -8,6 +8,7 @@
 #include <limits.h>
 #include <string.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <SDL.h>
 #include <zlib.h>
 #include <inttypes.h>
