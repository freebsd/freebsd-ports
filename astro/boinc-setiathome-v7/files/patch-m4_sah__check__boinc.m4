--- m4/sah_check_boinc.m4.orig	2008-09-09 16:55:19 UTC
+++ m4/sah_check_boinc.m4
@@ -30,7 +30,7 @@ AC_DEFUN([SAH_CHECK_BOINC],[
 	cd $thisdir
 	break
       else
-        if $FIND $boinc_dir -name "std_fixes.h" >& /dev/null
+        if $FIND $boinc_dir -name "std_fixes.h" > /dev/null
 	then
 	  BOINCDIR=`$FIND $boinc_dir -name "std_fixes.h" -print | $HEAD -1 | sed 's/\/std_fixes.h//'`         
           cd $BOINCDIR/..
