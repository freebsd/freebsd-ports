--- aclocal.m4.tmp	Wed Apr 17 11:05:05 2002
+++ aclocal.m4	Wed Apr 17 11:11:43 2002
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
 
