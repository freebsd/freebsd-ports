--- aclocal.m4.orig	Mon May 13 00:01:38 2002
+++ aclocal.m4	Mon May 13 00:06:09 2002
@@ -61,7 +61,7 @@
 missing_dir=`cd $ac_aux_dir && pwd`
 AM_MISSING_PROG(ACLOCAL, aclocal, $missing_dir)
 AM_MISSING_PROG(AUTOCONF, autoconf, $missing_dir)
-AM_MISSING_PROG(AUTOMAKE, automake, $missing_dir)
+AM_MISSING_PROG(AUTOMAKE, automake14, $missing_dir)
 AM_MISSING_PROG(AUTOHEADER, autoheader, $missing_dir)
 AM_MISSING_PROG(MAKEINFO, makeinfo, $missing_dir)
 AC_REQUIRE([AC_PROG_MAKE_SET])])
