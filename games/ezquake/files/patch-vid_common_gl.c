--- vid_common_gl.c.orig	Fri Jan  4 07:13:37 2008
+++ vid_common_gl.c	Fri Jan  4 07:15:29 2008
@@ -68,6 +68,9 @@
 lpMTexFUNC qglMultiTexCoord2f = NULL;
 lpSelTexFUNC qglActiveTexture = NULL;
 
+PFNGLXGETVIDEOSYNCSGIPROC qglXGetVideoSyncSGI = NULL;
+PFNGLXWAITVIDEOSYNCSGIPROC qglXWaitVideoSyncSGI = NULL;
+
 qbool gl_combine = false;
 
 qbool gl_add_ext = false;
@@ -198,6 +201,10 @@
 	Cvar_ForceSet (&gl_strings, va("GL_VENDOR: %s\nGL_RENDERER: %s\n"
 		"GL_VERSION: %s\nGL_EXTENSIONS: %s", gl_vendor, gl_renderer, gl_version, gl_extensions));
     Cvar_Register (&gl_maxtmu2);
+
+	qglXGetVideoSyncSGI = GL_GetProcAddress("glXGetVideoSyncSGI");
+	qglXWaitVideoSyncSGI = GL_GetProcAddress("glXWaitVideoSyncSGI");
+
 #ifndef __APPLE__
 	glClearColor (1,0,0,0);
 #else
