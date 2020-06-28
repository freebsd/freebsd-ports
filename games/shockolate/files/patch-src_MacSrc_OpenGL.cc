--- src/MacSrc/OpenGL.cc.orig	2020-04-23 04:29:54 UTC
+++ src/MacSrc/OpenGL.cc
@@ -195,7 +195,7 @@ static GLuint loadShader(GLenum type, const char *file
     DEBUG("Loading shader %s", filename);
 
     char fb[256];
-    sprintf(fb, "shaders/%s", filename);
+    sprintf(fb, "%%DATADIR%%shaders/%s", filename);
 
     FILE* file = fopen(fb, "r");
     if(file == nullptr) {
