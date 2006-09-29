--- src/gra/2d/gui.h.orig	Thu Jun 22 17:11:02 2006
+++ src/gra/2d/gui.h	Tue Sep 26 21:23:20 2006
@@ -4,6 +4,7 @@
 #include <guichan.hpp>
 #include <guichan/sdl.hpp>
 #include <guichan/opengl.hpp>
+#include <guichan/opengl/openglsdlimageloader.hpp>
 #include <GL/gl.h>
 #include <sstream>
 
@@ -17,7 +18,7 @@
 {
 gcn::SDLInput* input;
 gcn::OpenGLGraphics* graphics;
-gcn::OpenGLImageLoader* imageLoader;
+gcn::OpenGLSDLImageLoader* imageLoader;
 gcn::SDLImageLoader* hostImageLoader;
 
 /*
