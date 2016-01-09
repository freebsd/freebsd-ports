--- lib/critcl/critcl.tcl.orig	2015-05-28 04:45:02 UTC
+++ lib/critcl/critcl.tcl
@@ -604,7 +604,8 @@ proc ::critcl::cconst {name rtype rvalue
     # funciton body.
 
     SkipIgnored [set file [This]]
-    AbortWhenCalledAfterBuild
+    # https://github.com/andreas-kupries/critcl/commit/4f20732
+    HandleDeclAfterBuild
 
     # A void result does not make sense for constants.
     if {$rtype eq "void"} {
@@ -4514,7 +4515,10 @@ proc ::critcl::Cat {path} {
     # Easier to write our own copy than requiring fileutil and then
     # using fileutil::cat.
 
-    set fd [open $path r]
+    # https://github.com/andreas-kupries/critcl/pull/61
+    if {[catch {set fd [open $path r]} err]} {
+	return
+    }
     set data [read $fd]
     close $fd
     return $data
