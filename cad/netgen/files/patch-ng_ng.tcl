--- ng/ng.tcl.orig	2010-06-08 09:33:22.000000000 +0700
+++ ng/ng.tcl	2010-06-08 09:33:39.000000000 +0700
@@ -26,7 +26,7 @@
     set ngdir $env(NETGENDIR) 
 }
 if { [string length $ngdir] == 0 } {
-    set ngdir "." 
+    set ngdir "/usr/local/bin" 
 }
 
 set nguserdir ""
