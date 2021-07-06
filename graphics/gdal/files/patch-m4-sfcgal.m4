Obtained from:	https://github.com/OSGeo/gdal/commit/b414b0a0594b3e9c175a001e8455819463039eb6

--- m4/sfcgal.m4.orig	2021-04-26 12:31:13 UTC
+++ m4/sfcgal.m4
@@ -53,6 +53,7 @@ AC_DEFUN([SFCGAL_INIT],[
   if test x"$with_sfcgal" = x"no" ; then
 
     AC_MSG_RESULT([SFCGAL support disabled])
+    HAVE_SFCGAL=no
     SFCGAL_CONFIG=no
 
   elif test x"$with_sfcgal" = x"yes" -o x"$with_sfcgal" = x"" ; then
@@ -159,7 +160,7 @@ AC_DEFUN([SFCGAL_INIT],[
 
   else
 
-    if test $ac_sfcgal_config_auto = "no" ; then
+    if test x"$with_sfcgal" != x"no" -a x"$with_sfcgal" != x ; then
       AC_MSG_ERROR([SFCGAL support explicitly enabled, but sfcgal-config could not be found])
     fi
 
