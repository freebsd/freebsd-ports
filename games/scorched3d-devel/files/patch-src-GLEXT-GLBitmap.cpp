--- ./src/GLEXT/GLBitmap.cpp.orig	Thu Feb 26 23:00:26 2004
+++ ./src/GLEXT/GLBitmap.cpp	Sun May 30 22:43:45 2004
@@ -22,7 +22,7 @@
 #include <math.h>
 #include <GLEXT/GLState.h>
 #include <GLEXT/GLBitmap.h>
-#include <SDL/SDL.h>
+#include <SDL11/SDL.h>
 
 GLBitmap::GLBitmap() :
 	width_(0), height_(0), alpha_(false), newbits_(0)
