--- lib/irrlicht/source/Irrlicht/COpenGLExtensionHandler.h.orig	2013-11-14 03:55:29.000000000 +0400
+++ lib/irrlicht/source/Irrlicht/COpenGLExtensionHandler.h	2014-10-28 06:46:08.000000000 +0300
@@ -60,6 +60,9 @@
 	#endif
 	#include <GL/gl.h>
 	#include <GL/glx.h>
+	#ifndef PFNGLBLENDEQUATIONPROC
+	typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC) (GLenum mode);
+	#endif
 	#if defined(_IRR_OPENGL_USE_EXTPOINTER_)
 	#include "glext.h"
 	#undef GLX_ARB_get_proc_address // avoid problems with local glxext.h
