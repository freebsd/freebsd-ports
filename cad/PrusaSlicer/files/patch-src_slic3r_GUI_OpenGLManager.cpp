--- src/slic3r/GUI/OpenGLManager.cpp.orig	2021-08-03 16:17:35 UTC
+++ src/slic3r/GUI/OpenGLManager.cpp
@@ -237,7 +237,8 @@ bool OpenGLManager::init_gl()
     if (!m_gl_initialized) {
         if (glewInit() != GLEW_OK) {
             BOOST_LOG_TRIVIAL(error) << "Unable to init glew library";
-            return false;
+	    /* Ugly fix for https://github.com/prusa3d/PrusaSlicer/issues/6396 */
+            //return false;
         }
         m_gl_initialized = true;
         if (GLEW_EXT_texture_compression_s3tc)
