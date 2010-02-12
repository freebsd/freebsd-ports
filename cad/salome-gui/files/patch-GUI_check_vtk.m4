--- adm_local/unix/config_files/check_vtk.m4.orig	2009-08-15 21:43:12.000000000 +0700
+++ adm_local/unix/config_files/check_vtk.m4	2009-08-15 21:43:20.000000000 +0700
@@ -91,7 +91,7 @@
 if test -z $vtk_suffix ; then
   vtk_suffix="yes"
 fi
-if test "x$vtk_suffix" == "xno" ; then
+if test "x$vtk_suffix" = "xno" ; then
   dnl in case user wrote --with-vtk-version=no, use empty suffix
   vtk_suffix=""
 fi
