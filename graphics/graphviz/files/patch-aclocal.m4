
$FreeBSD$

--- aclocal.m4.orig	Fri Apr 12 01:09:26 2002
+++ aclocal.m4	Thu Apr 25 13:37:28 2002
@@ -59,10 +59,10 @@
 AC_REQUIRE([AC_ARG_PROGRAM])
 dnl FIXME This is truly gross.
 missing_dir=`cd $ac_aux_dir && pwd`
-AM_MISSING_PROG(ACLOCAL, aclocal, $missing_dir)
-AM_MISSING_PROG(AUTOCONF, autoconf, $missing_dir)
-AM_MISSING_PROG(AUTOMAKE, automake, $missing_dir)
-AM_MISSING_PROG(AUTOHEADER, autoheader, $missing_dir)
+AM_MISSING_PROG(ACLOCAL, ${ACLOCAL}, $missing_dir)
+AM_MISSING_PROG(AUTOCONF, ${AUTOCONF}, $missing_dir)
+AM_MISSING_PROG(AUTOMAKE, ${AUTOMAKE}, $missing_dir)
+AM_MISSING_PROG(AUTOHEADER, ${AUTOHEADER}, $missing_dir)
 AM_MISSING_PROG(MAKEINFO, makeinfo, $missing_dir)
 AC_REQUIRE([AC_PROG_MAKE_SET])])
 
@@ -129,10 +129,13 @@
 
 # serial 46 AC_PROG_LIBTOOL
 AC_DEFUN([AC_PROG_LIBTOOL],
-[AC_REQUIRE([AC_LIBTOOL_SETUP])dnl
+[
+AC_REQUIRE([AC_OBJEXT])dnl
+AC_REQUIRE([AC_EXEEXT])dnl
 
 # This can be used to rebuild libtool when needed
 LIBTOOL_DEPS="$ac_aux_dir/ltmain.sh"
+$ac_aux_dir/ltconfig $LIBTOOL_DEPS
 
 # Always use our own libtool.
 LIBTOOL='$(SHELL) $(top_builddir)/libtool'
