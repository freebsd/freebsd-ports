--- ./extensions.cpp.orig	Wed Oct  4 11:21:15 2006
+++ ./extensions.cpp	Wed Oct  4 11:21:58 2006
@@ -1,5 +1,18 @@
 #include <stdlib.h>
 #include <string.h>
+#include <GL/gl.h>
+#include <GL/glext.h>
+#include <GL/glx.h>
+#include <GL/glxext.h>
+#include <GL/glut.h>
+
+//typedef void (*__GLXextFuncPtr)(void);
+//extern __GLXextFuncPtr glXGetProcAddressARB (const GLubyte *);
+extern __GLXextFuncPtr glXGetProcAddressARB (GLubyte *);
+//extern void ((*(glXGetProcAddressARB))(const GLubyte *procName))( void );
+//extern void (*glXGetProcAddressARB( GLubyte *))( void );
+
+__GLXextFuncPtr glXGetProcAddressARB(unsigned char*){}
 
 #ifdef __APPLE__
   #include <mach-o/dyld.h>
@@ -96,18 +109,26 @@
 {
 #if defined(__APPLE__) || defined(__linux__)
 	// GL_ARB_multitexture
-	pfglActiveTextureARB          = (glActiveTextureARBProcPtr) GLGETPROCADDRESS((GLCHAR const*)"glActiveTextureARB");
-	pfglClientActiveTextureARB    = (glClientActiveTextureARBProcPtr) GLGETPROCADDRESS((GLCHAR const*)"glClientActiveTextureARB");
+//	pfglActiveTextureARB          = (glActiveTextureARBProcPtr) GLGETPROCADDRESS((GLCHAR const*)"glActiveTextureARB");
+	pfglActiveTextureARB          = (glActiveTextureARBProcPtr) GLGETPROCADDRESS((GLCHAR *)"glActiveTextureARB");
+//	pfglClientActiveTextureARB    = (glClientActiveTextureARBProcPtr) GLGETPROCADDRESS((GLCHAR const*)"glClientActiveTextureARB");
+	pfglClientActiveTextureARB    = (glClientActiveTextureARBProcPtr) GLGETPROCADDRESS((GLCHAR *)"glClientActiveTextureARB");
 	if (!pfglActiveTextureARB) return false;
 	if (!pfglClientActiveTextureARB) return false;
 
         // GL_ARB_fragment_program
-        pfglGenProgramsARB           = (glGenProgramsARBProcPtr) GLGETPROCADDRESS((GLCHAR const*)"glGenProgramsARB");
-	pfglDeleteProgramsARB        = (glDeleteProgramsARBProcPtr) GLGETPROCADDRESS((GLCHAR const*)"glDeleteProgramsARB");
-	pfglBindProgramARB           = (glBindProgramARBProcPtr) GLGETPROCADDRESS((GLCHAR const*)"glBindProgramARB");
-	pfglProgramStringARB         = (glProgramStringARBProcPtr) GLGETPROCADDRESS((GLCHAR const*)"glProgramStringARB");
-	pfglProgramEnvParameter4fARB = (glProgramEnvParameter4fARBProcPtr) GLGETPROCADDRESS((GLCHAR const*)"glProgramEnvParameter4fARB");
-	pfglGetProgramivARB          = (glGetProgramivARBProcPtr) GLGETPROCADDRESS((GLCHAR const*)"glGetProgramivARB");
+//        pfglGenProgramsARB           = (glGenProgramsARBProcPtr) GLGETPROCADDRESS((GLCHAR const*)"glGenProgramsARB");
+        pfglGenProgramsARB           = (glGenProgramsARBProcPtr) GLGETPROCADDRESS((GLCHAR *)"glGenProgramsARB");
+//	pfglDeleteProgramsARB        = (glDeleteProgramsARBProcPtr) GLGETPROCADDRESS((GLCHAR const*)"glDeleteProgramsARB");
+	pfglDeleteProgramsARB        = (glDeleteProgramsARBProcPtr) GLGETPROCADDRESS((GLCHAR *)"glDeleteProgramsARB");
+//	pfglBindProgramARB           = (glBindProgramARBProcPtr) GLGETPROCADDRESS((GLCHAR const*)"glBindProgramARB");
+	pfglBindProgramARB           = (glBindProgramARBProcPtr) GLGETPROCADDRESS((GLCHAR *)"glBindProgramARB");
+//	pfglProgramStringARB         = (glProgramStringARBProcPtr) GLGETPROCADDRESS((GLCHAR const*)"glProgramStringARB");
+	pfglProgramStringARB         = (glProgramStringARBProcPtr) GLGETPROCADDRESS((GLCHAR *)"glProgramStringARB");
+//	pfglProgramEnvParameter4fARB = (glProgramEnvParameter4fARBProcPtr) GLGETPROCADDRESS((GLCHAR const*)"glProgramEnvParameter4fARB");
+	pfglProgramEnvParameter4fARB = (glProgramEnvParameter4fARBProcPtr) GLGETPROCADDRESS((GLCHAR *)"glProgramEnvParameter4fARB");
+//	pfglGetProgramivARB          = (glGetProgramivARBProcPtr) GLGETPROCADDRESS((GLCHAR const*)"glGetProgramivARB");
+	pfglGetProgramivARB          = (glGetProgramivARBProcPtr) GLGETPROCADDRESS((GLCHAR *)"glGetProgramivARB");
 	if (!pfglGenProgramsARB) return false;
 	if (!pfglDeleteProgramsARB) return false;
 	if (!pfglBindProgramARB) return false;
