--- Sources/GL/GLX/display_window_opengl.cpp.orig	Wed Apr 21 01:50:23 2004
+++ Sources/GL/GLX/display_window_opengl.cpp	Mon Dec 20 18:09:50 2004
@@ -352,6 +352,7 @@
 20
 void CL_DisplayWindow_OpenGL::setup_joysticks()
 {
+#if 0
 	// This could need some improvments, it doesn't look for
 	// /dev/input/jsX for example
 	char pathname[256];
@@ -391,6 +392,7 @@
 			done = true;
 		}
 	}
+#endif
 }
 void CL_DisplayWindow_OpenGL::destroy_window()

