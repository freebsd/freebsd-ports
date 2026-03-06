--- src/slic3r/GUI/OpenGLManager.cpp.orig	2025-10-02 19:32:12.000000000 +0200
+++ src/slic3r/GUI/OpenGLManager.cpp	2026-03-06 11:00:00.000000000 +0100
@@ -244,7 +244,11 @@
     if (!m_gl_initialized) {
         GLenum result = glewInit();
-        if (result != GLEW_OK) {
-            BOOST_LOG_TRIVIAL(error) << "Unable to init glew library";
+        if (result != GLEW_OK
+#ifdef GLEW_ERROR_NO_GLX_DISPLAY
+            && result != GLEW_ERROR_NO_GLX_DISPLAY
+#endif
+            ) {
+            BOOST_LOG_TRIVIAL(error) << "Unable to init glew library: " << (const char*)glewGetErrorString(result);
             return false;
         }
