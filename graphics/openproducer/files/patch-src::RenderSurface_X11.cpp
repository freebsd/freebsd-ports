--- src/RenderSurface_X11.cpp.orig	Fri Oct 17 19:14:39 2003
+++ src/RenderSurface_X11.cpp	Fri Oct 17 19:14:59 2003
@@ -16,7 +16,7 @@
 using namespace Producer; 
 
 // HP, SGI and SUN don't implement glXGetProcAddressARB...
-#if defined (__sgi) || defined (sun) || defined( __hpux ) 
+#if defined (__sgi) || defined (sun) || defined( __hpux ) || defined(__FreeBSD__)
 #include <dlfcn.h>
 void (*glXGetProcAddressARB(const GLubyte *procName))(void)
 {
