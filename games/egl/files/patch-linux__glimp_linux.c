--- ./linux/glimp_linux.c.orig	Tue May 23 20:05:59 2006
+++ ./linux/glimp_linux.c	Tue May 23 20:06:00 2006
@@ -282,6 +282,7 @@
 		glStatic.cDepthBits = X11_GetGLAttribute(GLX_DEPTH_SIZE);
 		glStatic.cStencilBits = X11_GetGLAttribute(GLX_STENCIL_SIZE);
 
+		X11_SetKMGrab(qFalse, qTrue);
 		return qTrue;
 	}
 
