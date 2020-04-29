--- build.tcl.orig	2020-02-19 04:07:06.000000000 +0000
+++ build.tcl	2020-04-29 09:52:24.419446000 +0000
@@ -507,6 +507,7 @@
 	lappend cmd exec >@ stdout 2>@ stderr
 	lappend cmd [info nameofexecutable]
 	lappend cmd $theapp
+	lappend cmd -cache [file join $selfdir cache]
 	if {$target ne {}} {
 	    lappend cmd -target $target
 	}
@@ -541,6 +542,7 @@
 	lappend cmd exec >@ stdout 2>@ stderr
 	lappend cmd [info nameofexecutable]
 	lappend cmd $theapp
+	lappend cmd -cache [file join $selfdir cache]
 	if {$target ne {}} {
 	    lappend cmd -target $target
 	}
