--- a52.h.orig	Sun Dec 11 01:57:32 2005
+++ a52.h	Sun Dec 11 02:42:30 2005
@@ -24,11 +24,7 @@
 #ifndef A52_H
 #define A52_H
 
-#include "../avcodec.h"
-
-#undef malloc
-#undef free
-#undef realloc
+#include <inttypes.h>
 
 #if defined(LIBA52_FIXED)
 typedef int32_t sample_t;
@@ -41,7 +37,7 @@
 typedef float level_t;
 #endif
 
-typedef struct a52_state_s a52_state_t;
+#include "a52_internal.h"
 
 #define A52_CHANNEL 0
 #define A52_MONO 1
