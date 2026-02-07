--- src/position.c.orig	2020-05-23 06:13:27 UTC
+++ src/position.c
@@ -22,7 +22,7 @@
 #include "cJSON.h"
 #include "display.h"
 #include "map.h"
-#include "nlarn.h"
+#include "extdefs.h"
 #include "position.h"
 
 #define POS_MAX_XY (1<<10)
