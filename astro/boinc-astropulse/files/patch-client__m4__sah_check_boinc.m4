--- m4/sah_check_boinc.m4.orig	2010-03-23 22:00:23.000000000 +0100
+++ m4/sah_check_boinc.m4	2011-03-13 16:32:29.000000000 +0100
@@ -30,7 +30,7 @@
 	cd $thisdir
 	break
       else
-        if $FIND $boinc_dir -name "std_fixes.h" >& /dev/null
+        if $FIND $boinc_dir -name "std_fixes.h" > /dev/null
 	then
 	  BOINCDIR=`$FIND $boinc_dir -name "std_fixes.h" -print | $HEAD -1 | sed 's/\/std_fixes.h//'`         
           cd $BOINCDIR/..
