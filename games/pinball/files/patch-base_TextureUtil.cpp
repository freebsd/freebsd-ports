--- ./base/TextureUtil.cpp.orig	Fri Nov  1 14:49:57 2002
+++ ./base/TextureUtil.cpp	Mon Nov 11 01:27:54 2002
@@ -18,7 +18,7 @@
 #if EM_DEBUG
 #include <GL/glu.h>
 #endif
-#include <SDL/SDL.h>
+#include <SDL.h>
 #include <SDL_image.h>
 
 extern "C" {
