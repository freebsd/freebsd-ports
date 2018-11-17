--- cmake/Modules/FindFAUST.cmake.orig	2018-11-17 16:56:13 UTC
+++ cmake/Modules/FindFAUST.cmake
@@ -27,7 +27,7 @@ if(FAUST_FOUND)
         # This is a static build of faust, hence
         # we have to add all the LLVM flags...
 
-        find_program(LLVM_CONFIG llvm-config HINTS /usr/bin /usr/local/bin /usr/local/opt/llvm/bin)
+        find_program(LLVM_CONFIG llvm-config${FAUST_LLVM_VERSION} HINTS /usr/bin /usr/local/bin /usr/local/opt/llvm/bin)
         if(NOT LLVM_CONFIG)
             message(FATAL_ERROR "Using a static Faust library requires LLVM tooling to be present in the path")
         endif()
