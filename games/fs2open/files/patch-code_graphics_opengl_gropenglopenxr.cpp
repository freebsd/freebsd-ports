--- code/graphics/opengl/gropenglopenxr.cpp.orig	2025-11-04 13:07:36 UTC
+++ code/graphics/opengl/gropenglopenxr.cpp
@@ -21,7 +21,7 @@
 #include "graphics/opengl/ShaderProgram.h"
 #include "osapi/osapi.h"
 
-#if defined __APPLE_CC__
+#if defined __APPLE_CC__ || defined __FreeBSD__
 
 //Not supported
 
@@ -38,7 +38,7 @@
 
 #include <SDL_syswm.h>
 
-#ifndef __APPLE_CC__
+#if !defined __APPLE_CC__ && !defined __FreeBSD__
 
 //SETUP FUNCTIONS OGL
 SCP_vector<const char*> gr_opengl_openxr_get_extensions() {
