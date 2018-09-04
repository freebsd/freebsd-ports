--- src/freedv_api.c.orig	2018-05-24 09:41:22 UTC
+++ src/freedv_api.c
@@ -36,7 +36,7 @@
 #ifdef __APPLE__
 #include <malloc/malloc.h>
 #else
-#include <malloc.h>
+#include <sys/malloc.h>
 #endif /* __APPLE__ */
 
 #include "fsk.h"
