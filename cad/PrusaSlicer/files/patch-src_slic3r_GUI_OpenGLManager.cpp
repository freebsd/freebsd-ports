--- src/slic3r/GUI/OpenGLManager.cpp.orig	2021-04-16 11:41:00 UTC
+++ src/slic3r/GUI/OpenGLManager.cpp
@@ -239,7 +239,8 @@ bool OpenGLManager::init_gl()
     if (!m_gl_initialized) {
         if (glewInit() != GLEW_OK) {
             BOOST_LOG_TRIVIAL(error) << "Unable to init glew library";
-            return false;
+	    /* Ugly fix for https://github.com/prusa3d/PrusaSlicer/issues/6396 */
+            //return false;
         }
         m_gl_initialized = true;
         if (GLEW_EXT_texture_compression_s3tc)
