--- src/Terrain.cpp.orig	Sat Dec 20 17:28:54 2003
+++ src/Terrain.cpp	Thu Sep  2 22:00:19 2004
@@ -26,6 +26,13 @@
 #include <iostream>
 #include <string>
 
+#ifndef _WIN32
+#include <dlfcn.h>
+#undef GLX_GLXEXT_LEGACY
+#include <GL/glx.h>
+#endif
+
+
 using namespace Demeter;
 using namespace std;
 
@@ -45,6 +52,7 @@
 PFNGLLOCKARRAYSEXTPROC glLockArraysEXT_ptr;
 PFNGLUNLOCKARRAYSEXTPROC glUnlockArraysEXT_ptr;
 PFNGLCLIENTACTIVETEXTUREARBPROC glClientActiveTextureARB_ptr;
+PFNGLXGETPROCADDRESSARBPROC glXGetProcAddressARB_ptr;
 
 extern void SafelyFillString(char *szSource, char *szTarget, int targetSize);
 
@@ -101,6 +109,8 @@
 
 void LoadGLExtensions()
 {
+	void*	h;
+
 #ifdef _WIN32
 	glMultiTexCoord2fARB_ptr = (PFNGLMULTITEXCOORD2FARBPROC) wglGetProcAddress("glMultiTexCoord2fARB");
 	glActiveTextureARB_ptr = (PFNGLACTIVETEXTUREARBPROC) wglGetProcAddress("glActiveTextureARB");
@@ -108,11 +118,24 @@
 	glUnlockArraysEXT_ptr = (PFNGLUNLOCKARRAYSEXTPROC) wglGetProcAddress("glUnlockArraysEXT");
 	glClientActiveTextureARB_ptr = (PFNGLCLIENTACTIVETEXTUREARBPROC) wglGetProcAddress("glClientActiveTextureARB");
 #else
-	glMultiTexCoord2fARB_ptr = glMultiTexCoord2fARB;
-	glActiveTextureARB_ptr = glActiveTextureARB;
-	glLockArraysEXT_ptr = glLockArraysEXT;
-	glUnlockArraysEXT_ptr = glUnlockArraysEXT;
-	glClientActiveTextureARB_ptr = glClientActiveTextureARB;
+	if ((h = dlopen(NULL, RTLD_LAZY)) == NULL) {
+		string msg("Unable to find symbol list for the main program.");
+		throw new DemeterException(msg);
+	}
+
+	glXGetProcAddressARB_ptr = (PFNGLXGETPROCADDRESSARBPROC) dlsym(h, "glXGetProcAddressARB");
+	if (glXGetProcAddressARB_ptr == NULL) {
+		string msg("Unable to find symbol \"glXGetProcAddressARB\".");
+		throw new DemeterException(msg);
+	}
+	
+	glMultiTexCoord2fARB_ptr = (PFNGLMULTITEXCOORD2FARBPROC) glXGetProcAddressARB_ptr((GLubyte*)"glMultiTexCoord2fARB");
+	glActiveTextureARB_ptr = (PFNGLACTIVETEXTUREARBPROC) glXGetProcAddressARB_ptr((GLubyte*)"glActiveTextureARB");
+	glLockArraysEXT_ptr = (PFNGLLOCKARRAYSEXTPROC) glXGetProcAddressARB_ptr((GLubyte*)"glLockArraysEXT");
+	glUnlockArraysEXT_ptr = (PFNGLUNLOCKARRAYSEXTPROC) glXGetProcAddressARB_ptr((GLubyte*)"glUnlockArraysEXT");
+	glClientActiveTextureARB_ptr = (PFNGLCLIENTACTIVETEXTUREARBPROC) glXGetProcAddressARB_ptr((GLubyte*)"glClientActiveTextureARB");
+
+	dlclose(h);
 #endif
 }
 
