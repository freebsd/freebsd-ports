--- build/cmake/modules/JasOpenGL.cmake.orig	2020-09-05 14:52:22 UTC
+++ build/cmake/modules/JasOpenGL.cmake
@@ -4,7 +4,7 @@
 
 if (JAS_ENABLE_OPENGL)
 	set(OpenGL_GL_PREFERENCE GLVND)
-	find_package(OpenGL ${JAS_REQUIRED})
+	find_package(OpenGL ${JAS_OPENGL_REQUIRED})
 	message("OpenGL library found: ${OPENGL_FOUND}")
 else()
 	set(OPENGL_FOUND false)
