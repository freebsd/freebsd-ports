--- samples/SampleRawApplication/SampleRawMain.cpp.orig	Sat Dec 20 17:28:54 2003
+++ samples/SampleRawApplication/SampleRawMain.cpp	Thu Sep  2 21:44:58 2004
@@ -28,6 +28,12 @@
 #include <SDL.h>
 #include "Elevations.h"
 
+#ifndef _WIN32
+#include <dlfcn.h>
+#undef GLX_GLXEXT_LEGACY
+#include <GL/glx.h>
+#endif
+
 using namespace Demeter;
 using namespace std;
 
@@ -37,6 +43,7 @@
 #else
 typedef void (*PFNGLFOGCOORDPOINTERFARBPROC) (GLenum type,GLint stride,const GLvoid* pointer);
 #endif
+PFNGLXGETPROCADDRESSARBPROC glXGetProcAddressARB_ptr = NULL;
 PFNGLFOGCOORDPOINTERFARBPROC FogCoordPointerEXT = NULL;
 #ifndef FOG_COORDINATE_ARRAY_EXT
 #define FOG_COORDINATE_ARRAY_EXT	0x8457
@@ -193,7 +200,22 @@
 #ifdef _WIN32
 		FogCoordPointerEXT = (PFNGLFOGCOORDPOINTERFARBPROC) wglGetProcAddress("glFogCoordPointerEXT");
 #else
-		FogCoordPointerEXT = glFogCoordPointerEXT;
+		void*	h;
+
+		if ((h = dlopen(NULL, RTLD_LAZY)) == NULL) {
+			string msg("Unable to find symbol list for the main program.");
+			throw new DemeterException(msg);
+		}
+
+		glXGetProcAddressARB_ptr = (PFNGLXGETPROCADDRESSARBPROC) dlsym(h, "glXGetProcAddressARB");
+		if (glXGetProcAddressARB_ptr == NULL) {
+			string msg("Unable to find symbol \"glXGetProcAddressARB\".");
+			throw new DemeterException(msg);
+		}
+		
+		FogCoordPointerEXT = (PFNGLFOGCOORDPOINTERFARBPROC) glXGetProcAddressARB_ptr((GLubyte*)"glFogCoordPointerEXT");
+
+		dlclose(h);
 #endif
 		if (FogCoordPointerEXT != NULL)
 		{
