--- lib/ivis_opengl/screen.cpp.orig	2013-12-12 02:20:34 UTC
+++ lib/ivis_opengl/screen.cpp
@@ -261,7 +261,7 @@ void screen_EnableMissingFunctions()
 		__glewUseProgram = __glewUseProgramObjectARB;
 		__glewGetShaderiv = __glewGetObjectParameterivARB;
 		__glewLinkProgram = __glewLinkProgramARB;
-		__glewShaderSource = __glewShaderSourceARB;
+		__glewShaderSource = reinterpret_cast<PFNGLSHADERSOURCEPROC>(__glewShaderSourceARB);
 		__glewUniform1f = __glewUniform1fARB;
 		__glewUniform1i = __glewUniform1iARB;
 		__glewUniform4fv = __glewUniform4fvARB;
