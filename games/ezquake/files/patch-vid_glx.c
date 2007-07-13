--- ./vid_glx.c.orig	Thu Jul 12 20:11:59 2007
+++ ./vid_glx.c	Thu Jul 12 20:26:42 2007
@@ -138,9 +138,6 @@
 
 const char *glx_extensions=NULL;
 
-extern int glXGetVideoSyncSGI (unsigned int *);
-extern int glXWaitVideoSyncSGI (int, int, unsigned int *);
-
 cvar_t	vid_vsync = {"vid_vsync", "0"};
 
 void GL_Init_GLX(void);
@@ -567,10 +564,10 @@
 		double sanity_time = Sys_DoubleTime() + 0.05;
 		unsigned int count, latest;
 
-		glXGetVideoSyncSGI(&count);
+		qglXGetVideoSyncSGI(&count);
 
 		while(Sys_DoubleTime() < sanity_time) {
-			glXGetVideoSyncSGI(&latest);
+			qglXGetVideoSyncSGI(&latest);
 
 			if(latest != count) {
 				break;
