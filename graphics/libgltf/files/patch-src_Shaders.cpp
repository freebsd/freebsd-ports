--- src/Shaders.cpp.orig	2014-10-01 18:31:43 UTC
+++ src/Shaders.cpp
@@ -175,7 +175,7 @@ bool ShaderProgram::compileShader(const char* pShader,
         };
 
         const GLint aSizes[] = {
-            strlen("#version 130\n"),
+            sizeof("#version 130\n") - 1,
             iGLSize,
         };
 
