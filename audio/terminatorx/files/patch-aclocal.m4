--- aclocal.m4.orig	2018-11-07 18:55:24 UTC
+++ aclocal.m4
@@ -1,4 +1,4 @@
-# generated automatically by aclocal 1.15 -*- Autoconf -*-
+# generated automatically by aclocal 1.16 -*- Autoconf -*-
 
 # Copyright (C) 1996-2014 Free Software Foundation, Inc.
 
@@ -588,10 +588,10 @@ AS_VAR_IF([$1], [""], [$5], [$4])dnl
 # generated from the m4 files accompanying Automake X.Y.
 # (This private macro should not be called outside this file.)
 AC_DEFUN([AM_AUTOMAKE_VERSION],
-[am__api_version='1.15'
+[am__api_version='1.16'
 dnl Some users find AM_AUTOMAKE_VERSION and mistake it for a way to
 dnl require some minimum version.  Point them to the right macro.
-m4_if([$1], [1.15], [],
+m4_if([$1], [1.16], [],
       [AC_FATAL([Do not call $0, use AM_INIT_AUTOMAKE([$1]).])])dnl
 ])
 
@@ -607,7 +607,7 @@ m4_define([_AM_AUTOCONF_VERSION], [])
 # Call AM_AUTOMAKE_VERSION and AM_AUTOMAKE_VERSION so they can be traced.
 # This function is AC_REQUIREd by AM_INIT_AUTOMAKE.
 AC_DEFUN([AM_SET_CURRENT_AUTOMAKE_VERSION],
-[AM_AUTOMAKE_VERSION([1.15])dnl
+[AM_AUTOMAKE_VERSION([1.16])dnl
 m4_ifndef([AC_AUTOCONF_VERSION],
   [m4_copy([m4_PACKAGE_VERSION], [AC_AUTOCONF_VERSION])])dnl
 _AM_AUTOCONF_VERSION(m4_defn([AC_AUTOCONF_VERSION]))])
