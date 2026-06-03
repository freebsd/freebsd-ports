--- cmake/modules/LXQtCompilerSettings.cmake.orig	2026-04-26 06:06:29 UTC
+++ cmake/modules/LXQtCompilerSettings.cmake
@@ -164,7 +164,7 @@ if (CMAKE_COMPILER_IS_GNUCXX OR LXQT_COMPILER_IS_CLANG
         set(NO_UNDEFINED_FLAGS "-Wl,--no-undefined")
         # -Bsymbolic-functions: replace dynamic symbols used internally in
         #                       shared libs with direct addresses.
-        set(SYMBOLIC_FLAGS "-Wl,-Bsymbolic-functions")
+        set(SYMBOLIC_FLAGS "")
     endif()
 
     set(CMAKE_SHARED_LINKER_FLAGS
