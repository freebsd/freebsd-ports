--- raster3d/r3.showdspf/Ball.c.orig	2021-07-04 15:32:42 UTC
+++ raster3d/r3.showdspf/Ball.c
@@ -7,8 +7,6 @@
 #include "Ball.h"
 #include "BallMath.h"
 #include <stdio.h>
-#define TRUE 1
-#define FALSE 0
 
 HMatrix mId = { {1, 0, 0, 0}
 , {0, 1, 0, 0}
