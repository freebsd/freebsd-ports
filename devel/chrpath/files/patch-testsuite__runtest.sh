--- testsuite/runtest.sh.orig	2025-02-22 12:45:08 UTC
+++ testsuite/runtest.sh
@@ -7,7 +7,7 @@
 retval=0
 
 rm prog
-make prog
+gmake prog
 
 if $CHRPATH -h ; then
     echo "success: chrpath -h worked."
