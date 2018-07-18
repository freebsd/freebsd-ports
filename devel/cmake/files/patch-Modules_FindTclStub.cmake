--- Modules/FindTclStub.cmake.orig	2018-07-18 21:37:55.827263000 +0800
+++ Modules/FindTclStub.cmake	2018-07-18 21:46:40.911277000 +0800
@@ -101,6 +101,7 @@
   NAMES
   tclstub
   tclstub${TK_LIBRARY_VERSION} tclstub${TCL_TCLSH_VERSION} tclstub${TK_WISH_VERSION}
+  tclstub87 tclstub8.7
   tclstub86 tclstub8.6
   tclstub85 tclstub8.5
   tclstub84 tclstub8.4
@@ -114,6 +115,7 @@
   NAMES
   tkstub
   tkstub${TCL_LIBRARY_VERSION} tkstub${TCL_TCLSH_VERSION} tkstub${TK_WISH_VERSION}
+  tkstub87 tkstub8.7
   tkstub86 tkstub8.6
   tkstub85 tkstub8.5
   tkstub84 tkstub8.4
