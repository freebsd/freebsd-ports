--- tools/cling/tools/driver/cling.cpp.orig	2018-08-14 07:04:11 UTC
+++ tools/cling/tools/driver/cling.cpp
@@ -76,7 +76,7 @@ int main( int argc, char **argv ) {
 #endif
 
   // Set up the interpreter
-  cling::Interpreter Interp(argc, argv);
+  cling::Interpreter Interp(argc, argv, "%%LLVM_PREFIX%%/");
   const cling::InvocationOptions& Opts = Interp.getOptions();
 
   if (!Interp.isValid()) {
