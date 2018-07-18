--- cmake/FindTCL.cmake.orig	2018-07-14 10:35:10 UTC
+++ cmake/FindTCL.cmake
@@ -99,6 +99,7 @@ endif()
 
 find_library(TCL_LIBRARY
   NAMES
+  tcl87 tcl8.7
   tcl86 tcl8.6
   tcl85 tcl8.5
   tcl
@@ -128,6 +129,7 @@ set(TCL_POSSIBLE_INCLUDE_PATHS
   /usr/local/include
   /usr/include/tcl${TCL_VERSION}
   /usr/local/include/tcl${TCL_VERSION}
+  /usr/local/include/tcl8.7
   /usr/local/include/tcl8.6
   /usr/local/include/tcl8.5
   )
