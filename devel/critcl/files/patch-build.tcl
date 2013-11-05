--- build.tcl.orig	2013-11-05 09:27:29.000000000 +0100
+++ build.tcl	2013-11-05 09:28:22.000000000 +0100
@@ -249,7 +249,7 @@
 	set dsta [file dirname [file dirname [file normalize [info nameofexecutable]/___]]]
     } else {
 	set dstl $dst
-	set dsta [file dirname [findlib $dstl]]/bin
+	set dsta $dst/../bin
     }
 
     puts {Installing into:}
