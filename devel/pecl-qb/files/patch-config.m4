--- config.m4.orig	2014-07-21 00:45:49.000000000 +0000
+++ config.m4	2014-12-10 10:26:17.724992764 +0000
@@ -13,6 +13,9 @@
 PHP_ARG_WITH(cpu, whether to enable CPU-specific optimization,
 [  --with-cpu[=arch]         Enable optimization specific to CPU archecture], no, no)
 
+PHP_ARG_WITH(libmissing, whether to link libmissing,
+[  --with-libmissing[=prefix]         Link libmissing], no, no)
+
 if test "$PHP_QB" != "no"; then
   qb_cflags=""
 
@@ -37,6 +40,13 @@
     	qb_cflags="$qb_cflags -march=$PHP_CPU"
     fi
   fi
+
+  if test "$PHP_LIBMISSING" != "no"; then
+    LIBMISSING_INCDIR="$PHP_LIBMISSING/include"
+    LIBMISSING_LIBDIR="$PHP_LIBMISSING/lib"
+    PHP_ADD_LIBRARY_WITH_PATH("missing", $LIBMISSING_LIBDIR, QB_SHARED_LIBADD)
+    PHP_ADD_INCLUDE($LIBMISSING_INCDIR)
+  fi
   
   AC_MSG_CHECKING([whether CC supports -march=native])
   ac_saved_cflags="$CFLAGS"
