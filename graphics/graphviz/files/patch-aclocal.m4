--- aclocal.m4.orig	Tue Feb 18 18:22:38 2003
+++ aclocal.m4	Tue Feb 18 18:24:43 2003
@@ -144,10 +144,10 @@
 # Some tools Automake needs.
 AC_REQUIRE([AM_SANITY_CHECK])dnl
 AC_REQUIRE([AC_ARG_PROGRAM])dnl
-AM_MISSING_PROG(ACLOCAL, aclocal)
-AM_MISSING_PROG(AUTOCONF, autoconf)
-AM_MISSING_PROG(AUTOMAKE, automake)
-AM_MISSING_PROG(AUTOHEADER, autoheader)
+AM_MISSING_PROG(ACLOCAL, ${ACLOCAL})
+AM_MISSING_PROG(AUTOCONF, ${AUTOCONF})
+AM_MISSING_PROG(AUTOMAKE, ${AUTOMAKE})
+AM_MISSING_PROG(AUTOHEADER, ${AUTOHEADER})
 AM_MISSING_PROG(MAKEINFO, makeinfo)
 AM_MISSING_PROG(AMTAR, tar)
 AM_PROG_INSTALL_SH
@@ -563,10 +563,13 @@
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
