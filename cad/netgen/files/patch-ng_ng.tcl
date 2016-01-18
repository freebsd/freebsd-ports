--- ng/ng.tcl.orig	2014-08-29 09:54:01 UTC
+++ ng/ng.tcl
@@ -32,7 +32,7 @@ if { [lsearch [array names env] NETGENDI
     set ngdir $env(NETGENDIR) 
 }
 if { [string length $ngdir] == 0 } {
-    set ngdir "." 
+    set ngdir "/usr/local/bin" 
 }
 
 set nguserdir ""
