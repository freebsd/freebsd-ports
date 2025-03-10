--- src/api/utf8.c.orig	2025-01-21 19:20:49 UTC
+++ src/api/utf8.c
@@ -29,6 +29,7 @@
 #include <lualib.h>
 
 #include <assert.h>
+#include <limits.h>
 #include <string.h>
 #include <stdint.h>
 #include <stdlib.h>
