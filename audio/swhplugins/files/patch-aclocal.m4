--- aclocal.m4.orig	Fri Nov  1 21:13:15 2002
+++ aclocal.m4	Thu Dec 12 11:25:52 2002
@@ -59,10 +59,10 @@
 AC_REQUIRE([AC_ARG_PROGRAM])
 dnl FIXME This is truly gross.
 missing_dir=`cd $ac_aux_dir && pwd`
-AM_MISSING_PROG(ACLOCAL, aclocal, $missing_dir)
-AM_MISSING_PROG(AUTOCONF, autoconf, $missing_dir)
-AM_MISSING_PROG(AUTOMAKE, automake, $missing_dir)
-AM_MISSING_PROG(AUTOHEADER, autoheader, $missing_dir)
+AM_MISSING_PROG(ACLOCAL, aclocal14, $missing_dir)
+AM_MISSING_PROG(AUTOCONF, autoconf213, $missing_dir)
+AM_MISSING_PROG(AUTOMAKE, automake14, $missing_dir)
+AM_MISSING_PROG(AUTOHEADER, autoheader213, $missing_dir)
 AM_MISSING_PROG(MAKEINFO, makeinfo, $missing_dir)
 AC_REQUIRE([AC_PROG_MAKE_SET])])
 
