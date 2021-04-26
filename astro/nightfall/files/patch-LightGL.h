--- LightGL.h.orig	2021-04-26 15:56:15 UTC
+++ LightGL.h
@@ -67,8 +67,8 @@
 #define VP_RV_WIDTH   300
 #define VP_RV_HEIGHT  250
 
-float   texture_minval[NUM_COMP];
-float   texture_maxval[NUM_COMP];
+extern float   texture_minval[NUM_COMP];
+extern float   texture_maxval[NUM_COMP];
 
 /* wedge primary */
 #define VP_WP_X0      0
