--- adm_local/unix/config_files/check_msg2qm.m4.orig	2009-07-21 15:54:14.000000000 +0700
+++ adm_local/unix/config_files/check_msg2qm.m4	2009-07-21 15:54:25.000000000 +0700
@@ -34,7 +34,7 @@
 	    [  --with-msg2qm=DIR               root directory path of MSG2QM installation],
 	    MSG2QM_DIR="$withval",MSG2QM_DIR="")
 
-if test "x$MSG2QM_DIR" == "x" ; then
+if test "x$MSG2QM_DIR" = "x" ; then
 
 # no --with-MSG2QM-dir option used
 
