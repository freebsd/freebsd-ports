--- aclocal.m4.orig	Thu Oct 24 11:02:25 2002
+++ aclocal.m4	Tue Nov 26 19:28:10 2002
@@ -60,10 +60,10 @@
 AC_REQUIRE([AC_ARG_PROGRAM])
 dnl FIXME This is truly gross.
 missing_dir=`cd $ac_aux_dir && pwd`
-AM_MISSING_PROG(ACLOCAL, aclocal-${am__api_version}, $missing_dir)
-AM_MISSING_PROG(AUTOCONF, autoconf, $missing_dir)
-AM_MISSING_PROG(AUTOMAKE, automake-${am__api_version}, $missing_dir)
-AM_MISSING_PROG(AUTOHEADER, autoheader, $missing_dir)
+AM_MISSING_PROG(ACLOCAL, aclocal${am__api_version}, $missing_dir)
+AM_MISSING_PROG(AUTOCONF, $AUTOCONF, $missing_dir)
+AM_MISSING_PROG(AUTOMAKE, automake${am__api_version}, $missing_dir)
+AM_MISSING_PROG(AUTOHEADER, $AUTOHEADER, $missing_dir)
 AM_MISSING_PROG(MAKEINFO, makeinfo, $missing_dir)
 AC_REQUIRE([AC_PROG_MAKE_SET])])
 
@@ -87,7 +87,7 @@
 # ----------------------------
 # Automake X.Y traces this macro to ensure aclocal.m4 has been
 # generated from the m4 files accompanying Automake X.Y.
-AC_DEFUN([AM_AUTOMAKE_VERSION],[am__api_version="1.4"])
+AC_DEFUN([AM_AUTOMAKE_VERSION],[am__api_version="14"])
 
 # AM_SET_CURRENT_AUTOMAKE_VERSION
 # -------------------------------
