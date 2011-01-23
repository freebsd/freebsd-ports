--- m4/sah_check_boinc.m4	(revision 633)
+++ m4/sah_check_boinc.m4	(working copy)
@@ -23,16 +23,16 @@
   do
     if test -d $boinc_dir 
     then
-      if test -f $boinc_dir/Makefile.am 
+      if test -f $boinc_dir/include/std_fixes.h -o -f $boinc_dir/lib/std_fixes.h
       then
         cd $boinc_dir
         BOINCDIR=`pwd`
 	cd $thisdir
 	break
       else
-        if $FIND $boinc_dir -name "Makefile.am" >& /dev/null
+        if $FIND $boinc_dir -name "std_fixes.h" >& /dev/null
 	then
-	  BOINCDIR=`$FIND $boinc_dir -name "Makefile.am" -print | $HEAD -1 | sed 's/\/Makefile.am//'`         
+	  BOINCDIR=`$FIND $boinc_dir -name "std_fixes.h" -print | $HEAD -1 | sed 's/\/std_fixes.h//'`         
           cd $BOINCDIR
           BOINCDIR=`pwd`
 	  cd $thisdir
