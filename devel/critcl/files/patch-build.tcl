--- build.tcl.orig	2017-08-25 03:29:15.000000000 +0000
+++ build.tcl	2017-09-27 10:53:21.223065000 +0000
@@ -323,7 +323,7 @@
 	set dsta [file dirname [file dirname [file normalize [info nameofexecutable]/___]]]
     } else {
 	set dstl [lindex $args 0]
-	set dsta [file dirname [findlib $dstl]]/bin
+	set dsta $dstl/../bin
     }
 
     set selfdir [file dirname $me]
@@ -369,7 +369,7 @@
 	set theapp [critapp $dsta]
 
 	set    c [open $theapp w]
-	puts  $c "#!/bin/sh\n# -*- tcl -*- \\\nexec [file dirname [file normalize [info nameofexecutable]/___]] \"\$0\" \$\{1+\"\$@\"\}\npackage require critcl::app\ncritcl::app::main \$argv"
+	puts  $c "#!/bin/sh\n# -*- tcl -*- \\\nexec [file dirname [file normalize [info nameofexecutable]/___]] \"\$0\" \$\{1+\"\$@\"\}\nlappend auto_path \[file join \[file dirname \[info script\]\] .. lib\]\npackage require critcl::app\ncritcl::app::main \$argv"
 	close $c
 	+x $theapp
 
@@ -395,6 +395,7 @@
 	    lappend cmd [info nameofexecutable]
 	}
 	lappend cmd $theapp
+	lappend cmd -cache [file join $selfdir cache]
 	if {$target ne {}} {
 	    lappend cmd -target $target
 	}
