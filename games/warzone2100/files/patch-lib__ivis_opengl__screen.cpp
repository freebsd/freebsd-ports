--- lib/ivis_opengl/screen.cpp.orig	2013-12-12 06:20:34.000000000 +0400
+++ lib/ivis_opengl/screen.cpp	2014-08-18 16:11:06.000000000 +0400
@@ -261,7 +261,7 @@
 		__glewUseProgram = __glewUseProgramObjectARB;
 		__glewGetShaderiv = __glewGetObjectParameterivARB;
 		__glewLinkProgram = __glewLinkProgramARB;
-		__glewShaderSource = __glewShaderSourceARB;
+		__glewShaderSource = reinterpret_cast<PFNGLSHADERSOURCEPROC>(__glewShaderSourceARB);
 		__glewUniform1f = __glewUniform1fARB;
 		__glewUniform1i = __glewUniform1iARB;
 		__glewUniform4fv = __glewUniform4fvARB;
