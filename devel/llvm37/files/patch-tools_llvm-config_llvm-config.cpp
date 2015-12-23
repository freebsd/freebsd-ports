--- tools/llvm-config/llvm-config.cpp.orig	2015-12-21 11:12:59.047349000 +0100
+++ tools/llvm-config/llvm-config.cpp	2015-12-21 11:14:08.881815000 +0100
@@ -360,8 +360,9 @@ int main(int argc, char **argv) {
           OS << ActiveLibDir << '/' << Lib;
         } else if (PrintLibs) {
           // If this is a typical library name, include it using -l.
-          if (Lib.startswith("lib") && Lib.endswith(".a")) {
-            OS << "-l" << Lib.slice(3, Lib.size()-2);
+          if (Lib.startswith("lib") && Lib.endswith(LTDL_SHLIB_EXT)) {
+            // sizeof counts trailing NULL
+            OS << "-l" << Lib.slice(3, Lib.size()-sizeof(LTDL_SHLIB_EXT)+1);
             continue;
           }
 
