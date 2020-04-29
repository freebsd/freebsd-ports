--- build.tcl.orig	2020-02-19 04:07:06 UTC
+++ build.tcl
@@ -507,6 +507,7 @@ proc _install {args} {
 	lappend cmd exec >@ stdout 2>@ stderr
 	lappend cmd [info nameofexecutable]
 	lappend cmd $theapp
+	lappend cmd -cache [file join $selfdir cache]
 	if {$target ne {}} {
 	    lappend cmd -target $target
 	}
