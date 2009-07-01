--- tk/library/text.tcl.orig	2009-07-01 21:42:12.000000000 +0200
+++ tk/library/text.tcl	2009-07-01 21:42:20.000000000 +0200
@@ -450,14 +450,6 @@
 }
 set tkPriv(prevPos) {}
 
-# The MouseWheel will typically only fire on Windows.  However,
-# someone could use the "event generate" command to produce one
-# on other platforms.
-
-bind Text <MouseWheel> {
-    %W yview scroll [expr {- (%D / 120) * 4}] units
-}
-
 if {[string equal "unix" $tcl_platform(platform)]} {
     # Support for mousewheels on Linux/Unix commonly comes through mapping
     # the wheel to the extended buttons.  If you have a mousewheel, find
