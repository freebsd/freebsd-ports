--- lz_nonslide.c.orig	2005-07-06 02:17:46 UTC
+++ lz_nonslide.c
@@ -19,10 +19,11 @@
 /* 
  * Document here
  */
+#include <sys/types.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <assert.h>
-#include <strings.h>
+#include <string.h>
 #ifdef DEBUG_PERF
 #include <sys/time.h>
 #include <sys/resource.h>
