--- aclocal.m4.orig	Mon Sep 29 22:00:33 2003
+++ aclocal.m4	Mon Sep 29 22:58:34 2003
@@ -77,10 +77,10 @@
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
@@ -567,6 +567,7 @@
 
 # This can be used to rebuild libtool when needed
 LIBTOOL_DEPS="$ac_aux_dir/ltmain.sh"
+$ac_aux_dir/ltconfig $LIBTOOL_DEPS
 
 # Always use our own libtool.
 LIBTOOL='$(SHELL) $(top_builddir)/libtool'
