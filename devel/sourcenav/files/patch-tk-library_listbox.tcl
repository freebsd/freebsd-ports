--- tk/library/listbox.tcl.orig	2009-07-01 21:40:14.000000000 +0200
+++ tk/library/listbox.tcl	2009-07-01 21:40:31.000000000 +0200
@@ -175,14 +175,6 @@
     %W scan dragto %x %y
 }
 
-# The MouseWheel will typically only fire on Windows.  However,
-# someone could use the "event generate" command to produce one
-# on other platforms.
-
-bind Listbox <MouseWheel> {
-    %W yview scroll [expr {- (%D / 120) * 4}] units
-}
-
 if {[string equal "unix" $tcl_platform(platform)]} {
     # Support for mousewheels on Linux/Unix commonly comes through mapping
     # the wheel to the extended buttons.  If you have a mousewheel, find
