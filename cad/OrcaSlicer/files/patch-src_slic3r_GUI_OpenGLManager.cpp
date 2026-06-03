--- src/slic3r/GUI/OpenGLManager.cpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/OpenGLManager.cpp
@@ -264,7 +264,11 @@ bool OpenGLManager::init_gl(bool popup_error)
     if (!m_gl_initialized) {
         glewExperimental = true;
         GLenum result = glewInit();
-        if (result != GLEW_OK) {
+        if (result != GLEW_OK
+#ifdef GLEW_ERROR_NO_GLX_DISPLAY
+            && result != GLEW_ERROR_NO_GLX_DISPLAY
+#endif
+            ) {
             BOOST_LOG_TRIVIAL(error) << "Unable to init glew library, Error: " << glewGetErrorString(result);
             return false;
         }
