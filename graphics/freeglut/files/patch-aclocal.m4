--- aclocal.m4.orig	Sat Jan 26 05:23:11 2002
+++ aclocal.m4	Fri Apr 25 11:25:34 2003
@@ -36,10 +36,10 @@
 AC_REQUIRE([AC_ARG_PROGRAM])
 dnl FIXME This is truly gross.
 missing_dir=`cd $ac_aux_dir && pwd`
-AM_MISSING_PROG(ACLOCAL, aclocal, $missing_dir)
-AM_MISSING_PROG(AUTOCONF, autoconf, $missing_dir)
-AM_MISSING_PROG(AUTOMAKE, automake, $missing_dir)
-AM_MISSING_PROG(AUTOHEADER, autoheader, $missing_dir)
+AM_MISSING_PROG(ACLOCAL, ${ACLOCAL})
+AM_MISSING_PROG(AUTOCONF, ${AUTOCONF})
+AM_MISSING_PROG(AUTOMAKE, ${AUTOMAKE})
+AM_MISSING_PROG(AUTOHEADER, ${AUTOHEADER})
 AM_MISSING_PROG(MAKEINFO, makeinfo, $missing_dir)
 AC_REQUIRE([AC_PROG_MAKE_SET])])
 
@@ -123,7 +123,8 @@
 AC_CACHE_LOAD
 
 # This can be used to rebuild libtool when needed
-LIBTOOL_DEPS="$ac_aux_dir/ltconfig $ac_aux_dir/ltmain.sh"
+LIBTOOL_DEPS="$ac_aux_dir/ltmain.sh"
+$ac_aux_dir/ltconfig $LIBTOOL_DEPS
 
 # Always use our own libtool.
 LIBTOOL='$(SHELL) $(top_builddir)/libtool'
