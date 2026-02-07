--- src/opengl/GLee.h.orig	2008-09-20 18:40:14.000000000 +0400
+++ src/opengl/GLee.h	2009-03-10 17:33:52.000000000 +0300
@@ -747,8 +747,6 @@
 
 	/* GLX */
 
-	typedef void (*__GLXextFuncPtr)(void);
-
 	#ifndef GLX_ARB_get_proc_address 
 	#define GLX_ARB_get_proc_address 1
 	extern __GLXextFuncPtr glXGetProcAddressARB (const GLubyte *);
