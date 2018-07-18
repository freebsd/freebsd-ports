--- Modules/FindTclsh.cmake.orig	2018-07-18 21:37:55.834809000 +0800
+++ Modules/FindTclsh.cmake	2018-07-18 21:47:04.152861000 +0800
@@ -68,6 +68,7 @@
 set(TCL_TCLSH_NAMES
   tclsh
   tclsh${TCL_LIBRARY_VERSION} tclsh${TK_LIBRARY_VERSION} tclsh${TK_WISH_VERSION}
+  tclsh87 tclsh8.7
   tclsh86 tclsh8.6
   tclsh85 tclsh8.5
   tclsh84 tclsh8.4
