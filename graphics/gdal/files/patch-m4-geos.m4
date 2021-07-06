Obtained from:	https://github.com/OSGeo/gdal/commit/b414b0a0594b3e9c175a001e8455819463039eb6

--- m4/geos.m4.orig	2021-04-26 12:31:16 UTC
+++ m4/geos.m4
@@ -55,6 +55,7 @@ AC_DEFUN([GEOS_INIT],[
 
     AC_MSG_RESULT([GEOS support disabled])
     GEOS_CONFIG=no
+    HAVE_GEOS=no
 
   elif test x"$with_geos" = x"yes" -o x"$with_geos" = x"" ; then
 
@@ -160,7 +161,7 @@ AC_DEFUN([GEOS_INIT],[
 
   else
 
-    if test $ac_geos_config_auto = "no" ; then
+    if test x"$with_geos" != x"no" -a x"$with_geos" != x ; then
       AC_MSG_ERROR([GEOS support explicitly enabled, but geos-config could not be found])
     fi
 
