--- build/env.cmake.orig	2026-03-25 20:33:21 UTC
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
 
@@ -485,7 +485,7 @@ if ( NOT CMAKE_INSTALL_LIBDIR )
 endif()
 
 if ( NOT CMAKE_INSTALL_LIBDIR )
-    set( CMAKE_INSTALL_LIBDIR ${CMAKE_INSTALL_PREFIX}/lib64 )
+    set( CMAKE_INSTALL_LIBDIR ${CMAKE_INSTALL_PREFIX}/lib )
 endif()
 
 function( ExportStatic name install )
