--- wrapper/main.cpp.orig	Fri Jul  2 21:57:48 2004
+++ wrapper/main.cpp	Fri Aug 13 21:21:15 2004
@@ -3,7 +3,7 @@
 #include <stdarg.h>
 #include <string.h>
 #include <unistd.h>
-#include <SDL/SDL.h>
+#include <SDL.h>
 #endif // _WIN32
 #include "glide.h"
 #include <stdlib.h>
@@ -20,9 +20,13 @@
 #endif // _WIN32
 
 
+#ifndef __FreeBSD__
 PFNGLACTIVETEXTUREARBPROC glActiveTextureARB;
+#endif
 PFNGLBLENDFUNCSEPARATEEXTPROC glBlendFuncSeparateEXT;
+#ifndef __FreeBSD__
 PFNGLMULTITEXCOORD2FARBPROC glMultiTexCoord2fARB;
+#endif
 PFNGLFOGCOORDFPROC glFogCoordfEXT;
 #ifdef _WIN32
 PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB;
@@ -501,6 +505,7 @@
 	if (isExtensionSupported("GL_ARB_texture_mirrored_repeat") == FALSE)
 		display_warning((unsigned char*)"Your video card doesn't support GL_ARB_texture_mirrored_repeat extension");
 
+#ifndef __FreeBSD__
 #ifdef _WIN32
 	glActiveTextureARB = (PFNGLACTIVETEXTUREARBPROC)wglGetProcAddress("glActiveTextureARB");
 	glMultiTexCoord2fARB = (PFNGLMULTITEXCOORD2FARBPROC)wglGetProcAddress("glMultiTexCoord2fARB");
@@ -508,6 +513,7 @@
    glActiveTextureARB = (PFNGLACTIVETEXTUREARBPROC)SDL_GL_GetProcAddress("glActiveTextureARB");
    glMultiTexCoord2fARB = (PFNGLMULTITEXCOORD2FARBPROC)SDL_GL_GetProcAddress("glMultiTexCoord2fARB");
 #endif // _WIN32
+#endif
 	glGetIntegerv(GL_MAX_TEXTURE_UNITS_ARB, &nbTextureUnits);
 	if (nbTextureUnits == 1) display_warning((unsigned char*)"You need a video card that has at least 2 texture units");
    
