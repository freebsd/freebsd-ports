--- src/slic3r/GUI/OpenGLManager.cpp.orig	2024-06-27 09:25:47 UTC
+++ src/slic3r/GUI/OpenGLManager.cpp
@@ -346,7 +346,7 @@ bool OpenGLManager::init_gl()
     if (!m_gl_initialized) {
       glewExperimental = true;
       GLenum err = glewInit();
-        if (err != GLEW_OK) {
+        if (err != GLEW_OK && err != GLEW_ERROR_NO_GLX_DISPLAY) {
             BOOST_LOG_TRIVIAL(error) << "Unable to init glew library: " << glewGetErrorString(err);
             return false;
         }
