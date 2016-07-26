--- src/tX_mouse.cc.orig	2011-01-30 21:01:32 UTC
+++ src/tX_mouse.cc
@@ -47,7 +47,8 @@
 #include "tX_global.h"
 #include "tX_engine.h"
 #include "tX_vtt.h"
-#include <stdlib.h>
+#include <cstdlib>
+#include <cmath>
 
 #define TX_MOUSE_SPEED_NORMAL 0.05
 #define TX_MOUSE_SPEED_WARP 250000
