--- src/tX_mouse.cc.orig	2018-11-07 18:49:45 UTC
+++ src/tX_mouse.cc
@@ -37,9 +37,9 @@
 #include "tX_global.h"
 #include "tX_engine.h"
 #include "tX_vtt.h"
-#include <stdlib.h>
+#include <cstdlib>
 #include <string.h>
-#include <math.h>
+#include <cmath>
 
 #define TX_MOUSE_SPEED_NORMAL 0.05
 #define TX_MOUSE_SPEED_WARP 250000
