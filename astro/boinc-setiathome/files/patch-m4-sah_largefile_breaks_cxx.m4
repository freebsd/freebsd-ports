--- m4/sah_largefile_breaks_cxx.m4.orig	Mon Nov 17 18:33:14 2003
+++ m4/sah_largefile_breaks_cxx.m4	Tue Mar  1 10:38:00 2005
@@ -18,7 +18,7 @@
     [AC_DEFINE([LARGEFILE_BREAKS_CXX],[1],
     ["Define to 1 if largefile support causes missing symbols in C++"] ) 
     tmp_res="yes"
-    sah_cxx_includes=`echo "#include  \"$BOINCDIR/lib/std_fixes.h\"" ; echo $sah_cxx_includes`
+    sah_cxx_includes=`echo "#include  <BOINC/std_fixes.h>" ; echo $sah_cxx_includes`
     ]
   )
   AC_MSG_RESULT($tmp_res)
