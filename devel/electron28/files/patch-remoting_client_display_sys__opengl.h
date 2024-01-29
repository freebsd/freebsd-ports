--- remoting/client/display/sys_opengl.h.orig	2022-02-28 16:54:41 UTC
+++ remoting/client/display/sys_opengl.h
@@ -9,7 +9,7 @@
 
 #if BUILDFLAG(IS_IOS)
 #include <OpenGLES/ES3/gl.h>
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #define GL_GLEXT_PROTOTYPES
 #include <GL/gl.h>
 #include <GL/glext.h>
