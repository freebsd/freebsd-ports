--- obj/rexximg.sh.orig	Mon Sep 12 19:14:53 2005
+++ obj/rexximg.sh	Mon Sep 12 19:19:11 2005
@@ -1,5 +1,11 @@
 #!/bin/sh
 
+if [ -z "$LD_LIBRARY_PATH" ]; then
+    export LD_LIBRARY_PATH="."
+else
+    export LD_LIBRARY_PATH=".:$LD_LIBRARY_PATH"
+fi
+
 # This shell script creates the initial OORexx image file 
 cp ../kernel/RexxClasses/*.orx . 
 cp ../kernel/bsd/*.orx . 
