--- Modules/Compiler/Clang.cmake.orig	2026-01-04 12:06:32 UTC
+++ Modules/Compiler/Clang.cmake
@@ -62,7 +62,7 @@ else()
     # '-flto=thin' available since Clang 3.9 and Xcode 8
     # * http://clang.llvm.org/docs/ThinLTO.html#clang-llvm
     # * https://trac.macports.org/wiki/XcodeVersionInfo
-    set(_CMAKE_LTO_THIN TRUE)
+    #set(_CMAKE_LTO_THIN TRUE)
     if(__is_apple_clang)
       if(CMAKE_${lang}_COMPILER_VERSION VERSION_LESS 8.0)
         set(_CMAKE_LTO_THIN FALSE)
