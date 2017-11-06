--- cmake/modules/FindLit.cmake.orig	2016-10-20 04:49:37 UTC
+++ cmake/modules/FindLit.cmake
@@ -5,7 +5,7 @@
 # LIT_EXECUTABLE
 
 find_program(LIT_EXECUTABLE
-             NAMES lit
+             NAMES lit llvm-lit llvm-lit-devel
              DOC "Path to 'lit' executable")
 
 # Handle REQUIRED and QUIET arguments, this will also set LIT_FOUND to true
