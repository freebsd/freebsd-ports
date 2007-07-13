--- ./vid_common_gl.c.orig	Thu Jul 12 20:11:59 2007
+++ ./vid_common_gl.c	Thu Jul 12 20:29:47 2007
@@ -51,6 +51,9 @@
 lpMTexFUNC qglMultiTexCoord2f = NULL;
 lpSelTexFUNC qglActiveTexture = NULL;
 
+PFNGLXGETVIDEOSYNCSGIPROC qglXGetVideoSyncSGI = NULL;
+PFNGLXWAITVIDEOSYNCSGIPROC qglXWaitVideoSyncSGI = NULL;
+
 qbool gl_combine = false;
 
 qbool gl_add_ext = false;
@@ -175,6 +178,9 @@
 	Cvar_Register (&gl_strings);
 	Cvar_ForceSet (&gl_strings, va("GL_VENDOR: %s\nGL_RENDERER: %s\n"
 		"GL_VERSION: %s\nGL_EXTENSIONS: %s", gl_vendor, gl_renderer, gl_version, gl_extensions));
+
+	qglXGetVideoSyncSGI = GL_GetProcAddress("glXGetVideoSyncSGI");
+	qglXWaitVideoSyncSGI = GL_GetProcAddress("glXWaitVideoSyncSGI");
 
 #ifndef __APPLE__
 	glClearColor (1,0,0,0);
