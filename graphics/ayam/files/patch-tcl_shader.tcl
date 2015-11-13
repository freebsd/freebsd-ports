--- tcl/shader.tcl.orig	2015-06-23 18:03:50 UTC
+++ tcl/shader.tcl
@@ -76,14 +76,14 @@
 
     foreach p $spathstr {
 	set files [glob -nocomplain "${p}/*${sext}"]
-	append allfiles "$files "
+	append temp "$files "
     }
 
     set allshaders ""
-    foreach f $allfiles {
+    foreach s $temp {
 	# silently omit unreadable shader files
-	if {[file readable $f]} {
-	    lappend allshaders $f
+	if {[file readable $s]} {
+	    lappend allshaders $s
 	}
     }
     # foreach
