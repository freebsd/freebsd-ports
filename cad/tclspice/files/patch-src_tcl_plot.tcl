--- src/tcl/plot.tcl.orig	Sat Jun 24 05:36:11 2006
+++ src/tcl/plot.tcl	Sat Jun 24 05:36:33 2006
@@ -1,6 +1,6 @@
 #!/bin/sh
 # WishFix \
-	exec wish -f "$0" ${1+"$@"}
+	exec %%WISH%% -f "$0" ${1+"$@"}
 ###
 
 package require spice
