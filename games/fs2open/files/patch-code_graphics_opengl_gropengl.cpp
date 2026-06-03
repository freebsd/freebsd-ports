--- code/graphics/opengl/gropengl.cpp.orig	2025-11-04 13:17:51 UTC
+++ code/graphics/opengl/gropengl.cpp
@@ -6,7 +6,7 @@
 #include <direct.h>
 #endif
 
-#if !defined __APPLE_CC__ && defined SCP_UNIX
+#if !defined __APPLE_CC__ && !defined __FreeBSD__ && defined SCP_UNIX
 #include<glad/glad_glx.h>
 //Required because X defines none and always, which is used later
 #undef None
@@ -1268,7 +1268,7 @@ bool gr_opengl_init(std::unique_ptr<os::GraphicsOperat
 		Error(LOCATION, "Failed to load OpenGL!");
 	}
 
-#if !defined __APPLE_CC__ && defined SCP_UNIX
+#if !defined __APPLE_CC__ && !defined __FreeBSD__ && defined SCP_UNIX
 	if (!gladLoadGLXLoader(GL_context->getLoaderFunction(), nullptr, 0)) {
 		Error(LOCATION, "Failed to load GLX!");
 	}
