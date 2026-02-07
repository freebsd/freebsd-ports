--- src/modules/graphics/opengl/GLee.h.orig	2011-05-04 20:00:10.000000000 +0400
+++ src/modules/graphics/opengl/GLee.h	2011-09-20 00:16:46.000000000 +0400
@@ -799,8 +799,6 @@
 
 	/* GLX */
 
-	typedef void (*__GLXextFuncPtr)(void);
-
 	#ifndef GLX_ARB_get_proc_address 
 	#define GLX_ARB_get_proc_address 1
 	    extern __GLXextFuncPtr glXGetProcAddressARB (const GLubyte *);
