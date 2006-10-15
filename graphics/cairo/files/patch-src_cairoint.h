--- src/cairoint.h.orig	Sun Oct 15 18:02:35 2006
+++ src/cairoint.h	Sun Oct 15 18:10:11 2006
@@ -50,6 +50,11 @@
 #include "config.h"
 #endif
 
+#ifndef INT16_MAX
+#define INT16_MAX 0x7fff
+#define INT16_MIN (-0x7fff-1)
+#endif
+
 #include <assert.h>
 #include <stdlib.h>
 #include <string.h>
