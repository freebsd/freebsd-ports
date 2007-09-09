--- Sources/GL/GLX/display_window_opengl.cpp.orig	Tue Oct 25 10:39:25 2005
+++ Sources/GL/GLX/display_window_opengl.cpp	Mon May  7 21:48:06 2007
@@ -333,6 +333,7 @@
 void
 CL_DisplayWindow_OpenGL::setup_event()
 {
+#if 0
 	char pathname[256];
 	bool done = false;
 
@@ -357,6 +358,7 @@
 			done = true;
 		}
 	}
+#endif
 }
 
 void CL_DisplayWindow_OpenGL::setup_usb_mice()
@@ -389,6 +391,7 @@
 
 void CL_DisplayWindow_OpenGL::setup_joysticks()
 {
+#if 0
 	// This could need some improvments, it doesn't look for
 	// /dev/input/jsX for example
 	char pathname[256];
@@ -428,6 +431,7 @@
 			done = true;
 		}
 	}
+#endif
 }
 
 
