--- ./src/GLEXT/GLBitmap.cpp.orig	Mon Sep  6 02:36:23 2004
+++ ./src/GLEXT/GLBitmap.cpp	Tue Jan 25 19:34:16 2005
@@ -22,7 +22,7 @@
 #include <math.h>
 #include <GLEXT/GLState.h>
 #include <GLEXT/GLBitmap.h>
-#include <SDL/SDL.h>
+#include <SDL11/SDL.h>
 
 GLBitmap::GLBitmap() :
 	width_(0), height_(0), alpha_(false), newbits_(0)
