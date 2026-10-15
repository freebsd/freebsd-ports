--- src/kex/w_wad.c.orig	2026-10-15 11:58:04 UTC
+++ src/kex/w_wad.c
@@ -45,7 +45,7 @@
 #endif
 
 #ifndef __APPLE__
-#include <malloc.h>
+#include <stdlib.h>
 #else
 #include <malloc/malloc.h>
 #endif
