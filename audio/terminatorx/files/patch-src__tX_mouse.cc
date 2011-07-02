--- src/tX_mouse.cc.orig	2011-01-31 06:01:32.000000000 +0900
+++ src/tX_mouse.cc	2011-04-02 11:56:20.000000000 +0900
@@ -47,7 +47,8 @@
 #include "tX_global.h"
 #include "tX_engine.h"
 #include "tX_vtt.h"
-#include <stdlib.h>
+#include <cstdlib>
+#include <cmath>
 
 #define TX_MOUSE_SPEED_NORMAL 0.05
 #define TX_MOUSE_SPEED_WARP 250000
