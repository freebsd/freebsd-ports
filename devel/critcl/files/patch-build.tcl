--- build.tcl.orig	2017-10-24 14:35:54 UTC
+++ build.tcl
@@ -426,6 +426,7 @@ proc _install {args} {
 	    lappend cmd [info nameofexecutable]
 	}
 	lappend cmd $theapp
+	lappend cmd -cache [file join $selfdir cache]
 	if {$target ne {}} {
 	    lappend cmd -target $target
 	}
