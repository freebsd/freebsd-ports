--- build/env.cmake.orig	2026-05-12 21:39:17 UTC
+++ build/env.cmake
@@ -470,8 +470,8 @@ if( Python3_EXECUTABLE )
   find_package( Python3 COMPONENTS Interpreter Development )
 # message(STATUS "Use: ${Python3_EXECUTABLE}")
 
-  execute_process( COMMAND
-         "${Python3_EXECUTABLE}" -m pip install --upgrade pip setuptools wheel )
+  # execute_process( COMMAND
+         # "${Python3_EXECUTABLE}" -m pip install --upgrade pip setuptools wheel )
  endif()
 endif()
 
