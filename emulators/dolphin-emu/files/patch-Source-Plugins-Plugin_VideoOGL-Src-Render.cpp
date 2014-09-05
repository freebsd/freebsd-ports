--- Source/Plugins/Plugin_VideoOGL/Src/Render.cpp.orig	2014-09-02 16:22:19.000000000 +0200
+++ Source/Plugins/Plugin_VideoOGL/Src/Render.cpp	2014-09-02 16:24:58.000000000 +0200
@@ -220,7 +220,7 @@
 #endif
 }
 
-void GLAPIENTRY ErrorCallback( GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const char* message, void* userParam)
+void GLAPIENTRY ErrorCallback( GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const char* message, const void* userParam)
 {
 	// GLES3 doesn't natively support this
 	// XXX: Include GLES2 extensions header so we can use this
