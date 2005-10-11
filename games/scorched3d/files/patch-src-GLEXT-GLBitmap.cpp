--- ./src/GLEXT/GLBitmap.cpp.orig	Sat Aug  6 13:57:38 2005
+++ ./src/GLEXT/GLBitmap.cpp	Tue Aug  9 23:21:13 2005
@@ -22,7 +22,7 @@
 #include <math.h>
 #include <GLEXT/GLState.h>
 #include <GLEXT/GLBitmap.h>
-#include <SDL/SDL.h>
+#include <SDL11/SDL.h>
 
 GLBitmap::GLBitmap() :
 	width_(0), height_(0), alpha_(false), newbits_(0)
