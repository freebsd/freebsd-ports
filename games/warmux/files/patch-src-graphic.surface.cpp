--- src/graphic/surface.cpp.orig	2011-04-28 21:03:06.000000000 +0200
+++ src/graphic/surface.cpp	2012-05-09 12:06:52.000000000 +0200
@@ -25,6 +25,7 @@
 #include <SDL_image.h>
 #include <SDL_rotozoom.h>
 #include <png.h>
+#include <zlib.h>
 
 #include "graphic/surface.h"
 #include "tool/math_tools.h"
