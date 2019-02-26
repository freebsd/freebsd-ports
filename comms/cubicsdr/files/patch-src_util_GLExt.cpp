--- src/util/GLExt.cpp.orig	2018-08-20 16:53:40 UTC
+++ src/util/GLExt.cpp
@@ -9,7 +9,7 @@
 #include <OpenGL/OpenGL.h>
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <dlfcn.h>
 #endif
 
@@ -60,7 +60,7 @@ void initGLExtensions() {
     CGLSetParameter (CGLGetCurrentContext(), kCGLCPSwapInterval, &interval);
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     dlopen("libglx.so",RTLD_LAZY);
 
     void (*glxSwapIntervalEXTFunc) (Display *dpy, GLXDrawable drawable, int interval) = 0;
