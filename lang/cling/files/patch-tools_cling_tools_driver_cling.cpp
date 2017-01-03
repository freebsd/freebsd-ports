--- tools/cling/tools/driver/cling.cpp.orig	2016-12-29 13:54:45 UTC
+++ tools/cling/tools/driver/cling.cpp
@@ -51,7 +51,7 @@ int main( int argc, char **argv ) {
 #endif
 
   // Set up the interpreter
-  cling::Interpreter interp(argc, argv);
+  cling::Interpreter interp(argc, argv, "%%LLVM_PREFIX%%/");
   if (interp.getOptions().Help) {
     return 0;
   }
