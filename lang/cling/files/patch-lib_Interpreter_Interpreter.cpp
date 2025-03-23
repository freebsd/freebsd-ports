--- lib/Interpreter/Interpreter.cpp.orig	2024-12-10 16:14:05 UTC
+++ lib/Interpreter/Interpreter.cpp
@@ -268,8 +268,7 @@ namespace cling {
     Preprocessor& PP = SemaRef.getPreprocessor();
 
     m_LookupHelper.reset(new LookupHelper(new Parser(PP, SemaRef,
-                                                     /*SkipFunctionBodies*/false,
-                                                     /*isTemp*/true), this));
+                                                     /*SkipFunctionBodies*/false), this));
     if (!m_LookupHelper)
       return;
 
