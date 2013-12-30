--- lib/GL/GLee.h.orig	2013-09-12 00:21:39.000000000 +0400
+++ lib/GL/GLee.h	2013-09-18 21:32:09.160519239 +0400
@@ -747,8 +747,6 @@
 
 	/* GLX */
 
-	typedef void (*__GLXextFuncPtr)(void);
-
 	#ifndef GLX_ARB_get_proc_address 
 	#define GLX_ARB_get_proc_address 1
 	extern __GLXextFuncPtr glXGetProcAddressARB (const GLubyte *);
