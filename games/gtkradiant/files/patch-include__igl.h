--- include/igl.h.orig	Fri Feb 10 19:01:20 2006
+++ include/igl.h	Sun Jul 22 14:31:40 2007
@@ -2643,7 +2643,7 @@
   GLhandleARB (QGL_DLLEXPORT *m_glCreateShaderObjectARB)(GLenum shaderType);
   void (QGL_DLLEXPORT *m_glShaderSourceARB)(GLhandleARB shaderObj, GLsizei count, const GLcharARB **string, const GLint *length);
   void (QGL_DLLEXPORT *m_glCompileShaderARB)(GLhandleARB shaderObj);
-  GLhandleARB (QGL_DLLEXPORT *m_glCreateProgramObjectARB)(GLvoid);
+  GLhandleARB (QGL_DLLEXPORT *m_glCreateProgramObjectARB)(void);
   void (QGL_DLLEXPORT *m_glAttachObjectARB)(GLhandleARB containerObj, GLhandleARB obj);
   void (QGL_DLLEXPORT *m_glLinkProgramARB)(GLhandleARB programObj);
   void (QGL_DLLEXPORT *m_glUseProgramObjectARB)(GLhandleARB programObj);
