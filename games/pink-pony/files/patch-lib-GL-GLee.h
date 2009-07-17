--- lib/GL/GLee.h.orig	2009-04-12 22:06:20.000000000 +0400
+++ lib/GL/GLee.h	2009-07-09 23:58:05.000000000 +0400
@@ -747,8 +747,6 @@
 
 	/* GLX */
 
-	typedef void (*__GLXextFuncPtr)(void);
-
 	#ifndef GLX_ARB_get_proc_address 
 	#define GLX_ARB_get_proc_address 1
 	extern __GLXextFuncPtr glXGetProcAddressARB (const GLubyte *);
