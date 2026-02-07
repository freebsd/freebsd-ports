--- cake/render.cpp.orig	Fri Dec  9 04:12:40 2005
+++ cake/render.cpp	Fri Dec  9 13:13:58 2005
@@ -21,6 +21,7 @@
 #ifdef WIN32
   #include "glsetup/glext.h"
 #else
+  #define GLX_GLXEXT_LEGACY
   #include <GL/glx.h>
   #include <GL/glext.h>
 #endif
@@ -36,13 +37,7 @@
   // size of float may change from one platform to one other
   #define XYZ_OFFSET            16    // 4 * sizeof(float)
 #else
-  #if !defined(GLX_VERSION_1_4)
-    #define lglGetProcAddress(p)    glXGetProcAddressARB((byte*) p);
-  #else
-    #define lglGetProcAddress(p)    glXGetProcAddress((byte*) p);
-    #define glActiveTextureARB      glActiveTexture
-    #define glClientActiveTextureARB  glClientActiveTexture
-  #endif
+  #define lglGetProcAddress(p)    glXGetProcAddressARB((byte*) p);
 
   // size of float may change from one platform to one other
   #define XYZ_OFFSET            16    // 4 * sizeof(float)
