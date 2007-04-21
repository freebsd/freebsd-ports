--- ./engine/renderer/qgl.h.orig	Sun Mar 25 16:56:34 2007
+++ ./engine/renderer/qgl.h	Mon Apr 16 23:58:33 2007
@@ -45,7 +45,7 @@
 
 #include "macosx_glimp.h"
 
-#elif defined( __linux__ )
+#elif defined( __unix__ )
 
 #include <GL/gl.h>
 #include <GL/glx.h>
@@ -325,7 +325,7 @@
 //===========================================================================
 
 // non-windows systems will just redefine qgl* to gl*
-#if !defined( _WIN32 ) && !defined(MACOS_X) && !defined( __linux__ ) && !defined( __FreeBSD__ ) // rb010123
+#if !defined( _WIN32 ) && !defined(MACOS_X) && !defined( __unix__ ) // rb010123
 
 #include "qgl_linked.h"
 
@@ -712,7 +712,7 @@
 
 #endif	// _WIN32
 
-#if ( (defined __linux__ )  || (defined __FreeBSD__ ) ) // rb010123
+#ifdef __unix__ // rb010123
 
 //FX Mesa Functions
 // bk001129 - from cvs1.17 (mkv)
@@ -733,8 +733,8 @@
 extern void (*qglXCopyContext)( Display *dpy, GLXContext src, GLXContext dst, GLuint mask );
 extern void (*qglXSwapBuffers)( Display *dpy, GLXDrawable drawable );
 
-#endif // __linux__ || __FreeBSD__ // rb010123
+#endif // __unix__ // rb010123
 
-#endif	// _WIN32 && __linux__
+#endif	// _WIN32 && __unix__
 
 #endif
