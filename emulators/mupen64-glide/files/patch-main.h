--- wrapper/main.h.orig	Sun Jun 20 21:08:48 2004
+++ wrapper/main.h	Fri Aug 13 21:17:22 2004
@@ -16,8 +16,10 @@
 void updateCombinera(int i);
 
 //#ifdef _WIN32
+#ifndef __FreeBSD__
 extern PFNGLACTIVETEXTUREARBPROC glActiveTextureARB;
 extern PFNGLMULTITEXCOORD2FARBPROC glMultiTexCoord2fARB;
+#endif
 extern PFNGLBLENDFUNCSEPARATEEXTPROC glBlendFuncSeparateEXT;
 extern PFNGLFOGCOORDFPROC glFogCoordfEXT;
 //#endif // _WIN32
