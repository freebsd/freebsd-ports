--- m4/sah_check_boinc.m4.orig	2008-09-09 18:55:19.000000000 +0200
+++ m4/sah_check_boinc.m4	2011-03-13 16:24:18.000000000 +0100
@@ -30,7 +30,7 @@
 	cd $thisdir
 	break
       else
-        if $FIND $boinc_dir -name "std_fixes.h" >& /dev/null
+        if $FIND $boinc_dir -name "std_fixes.h" > /dev/null
 	then
 	  BOINCDIR=`$FIND $boinc_dir -name "std_fixes.h" -print | $HEAD -1 | sed 's/\/std_fixes.h//'`         
           cd $BOINCDIR/..
