--- src/slic3r/GUI/OpenGLManager.cpp.orig	2023-07-21 19:13:54 UTC
+++ src/slic3r/GUI/OpenGLManager.cpp
@@ -336,7 +336,7 @@ bool OpenGLManager::init_gl()
         glewExperimental = true;
 #endif // ENABLE_GL_CORE_PROFILE || ENABLE_OPENGL_ES
         GLenum err = glewInit();
-        if (err != GLEW_OK) {
+        if (err != GLEW_OK && err != GLEW_ERROR_NO_GLX_DISPLAY) {
             BOOST_LOG_TRIVIAL(error) << "Unable to init glew library: " << glewGetErrorString(err);
             return false;
         }
