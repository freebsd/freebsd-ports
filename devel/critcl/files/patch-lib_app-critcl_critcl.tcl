--- lib/app-critcl/critcl.tcl.orig	2020-02-19 04:07:06 UTC
+++ lib/app-critcl/critcl.tcl
@@ -174,7 +174,8 @@ proc ::critcl::app::PackageCache {} {
     if {$v::cache ne {}} {
 	return $v::cache
     }
-    return [file join ~ .critcl pkg[pid].[clock seconds]]
+    set home [expr {[info exists ::env(CRITCL_HOME)] ? $::env(CRITCL_HOME) : {~}}]
+    return [file join $home .critcl pkg[pid].[clock seconds]]
 }
 
 proc ::critcl::app::StopOnFailed {} {
