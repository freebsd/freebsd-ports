--- Modules/FindTCL.cmake.orig	2018-07-18 21:37:55.956332000 +0800
+++ Modules/FindTCL.cmake	2018-07-18 21:45:48.214853000 +0800
@@ -85,6 +85,8 @@
 )
 
 set(TCLTK_POSSIBLE_LIB_PATH_SUFFIXES
+  lib/tcl/tcl8.7
+  lib/tcl/tk8.7
   lib/tcl/tcl8.6
   lib/tcl/tk8.6
   lib/tcl/tcl8.5
@@ -116,6 +118,7 @@
   NAMES
   tcl
   tcl${TCL_LIBRARY_VERSION} tcl${TCL_TCLSH_VERSION} tcl${TK_WISH_VERSION}
+  tcl87 tcl8.7 tcl87t tcl8.7t
   tcl86 tcl8.6 tcl86t tcl8.6t
   tcl85 tcl8.5
   tcl84 tcl8.4
@@ -130,6 +133,7 @@
   NAMES
   tk
   tk${TK_LIBRARY_VERSION} tk${TCL_TCLSH_VERSION} tk${TK_WISH_VERSION}
+  tk87 tk8.7 tk87t tk8.7t
   tk86 tk8.6 tk86t tk8.6t
   tk85 tk8.5
   tk84 tk8.4
@@ -176,6 +180,8 @@
 set(TCLTK_POSSIBLE_INCLUDE_PATH_SUFFIXES
   include/tcl${TK_LIBRARY_VERSION}
   include/tcl${TCL_LIBRARY_VERSION}
+  include/tcl8.7
+  include/tk8.7
   include/tcl8.6
   include/tk8.6
   include/tcl8.5
