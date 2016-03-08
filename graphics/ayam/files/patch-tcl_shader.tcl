--- tcl/shader.tcl.orig	2016-01-13 20:09:57 UTC
+++ tcl/shader.tcl
@@ -76,14 +76,14 @@ proc shader_scanAll {} {
 
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
