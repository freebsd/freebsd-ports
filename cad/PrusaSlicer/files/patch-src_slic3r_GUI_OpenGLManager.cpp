--- src/slic3r/GUI/OpenGLManager.cpp.orig	2024-02-29 13:03:32 UTC
+++ src/slic3r/GUI/OpenGLManager.cpp
@@ -344,7 +344,7 @@ bool OpenGLManager::init_gl()
         glewExperimental = true;
 #endif // ENABLE_GL_CORE_PROFILE || ENABLE_OPENGL_ES
         GLenum err = glewInit();
-        if (err != GLEW_OK) {
+        if (err != GLEW_OK && err != GLEW_ERROR_NO_GLX_DISPLAY) {
             BOOST_LOG_TRIVIAL(error) << "Unable to init glew library: " << glewGetErrorString(err);
             return false;
         }
