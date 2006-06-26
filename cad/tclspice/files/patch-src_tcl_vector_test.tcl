--- src/tcl/vector_test.tcl.orig	Sat Jun 24 05:37:20 2006
+++ src/tcl/vector_test.tcl	Sat Jun 24 05:37:14 2006
@@ -1,6 +1,6 @@
 #!/bin/sh
 # WishFix \
-	exec wish -f "$0" ${1+"$@"}
+	exec %%WISH%% -f "$0" ${1+"$@"}
 ###
 
 package require BLT
