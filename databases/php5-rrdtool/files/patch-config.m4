--- config.m4.orig	Wed Nov 30 19:44:51 2005
+++ config.m4	Sun Mar 19 20:48:34 2006
@@ -13,7 +13,7 @@
 [  --with-rrdtool[=DIR]       Include rrdtool support (requires rrdtool >= 1.0.49).])
 
 if test "$PHP_RRDTOOL" != "no"; then
-
+  PHP_NEW_EXTENSION(rrdtool, rrdtool.c, $ext_shared)
   if test "$PHP_RRDTOOL" != "yes"; then
   AC_MSG_CHECKING(if rrdtool specified path is valid)
     if test -r $PHP_RRDTOOL/include/rrd.h && test -f $PHP_RRDTOOL/lib/librrd.$SHLIB_SUFFIX_NAME -o -f $PHP_RRDTOOL/lib/librrd.a; then # path given as parameter
@@ -51,7 +51,14 @@
     fi
   fi
 
-dnl Finish the setup
+
+  dnl PHP Libaries include
+  AC_DEFINE(HAVE_RRDTOOL,1,[ ])
+  PHP_SUBST(RRDTOOL_SHARED_LIBADD)
+  PHP_ADD_LIBRARY_WITH_PATH(rrd, $RRDTOOL_LIBDIR, RRDTOOL_SHARED_LIBADD)
+  PHP_ADD_INCLUDE($RRDTOOL_INCDIR)
+
+  dnl Finish the setup
 
   RRD_H_PATH="$RRDTOOL_INCDIR/rrd.h"
   PHP_RRDTOOL_DIR=$RRDTOOL_DIR
@@ -59,14 +66,9 @@
 
   PHP_CHECK_LIBRARY(rrd, rrd_create,
   [],[
-    PHP_CHECK_LIBRARY(rrd, rrd_create,
-    [],[
-      AC_MSG_ERROR([wrong rrd lib version or lib not found])
-    ],[
-      -L$RRDTOOL_LIBDIR -ldl
-    ])
+    AC_MSG_ERROR([wrong rrd lib version or lib not found])
   ],[
-    -L$RRDTOOL_LIBDIR -ldl
+    -L$RRDTOOL_LIBDIR
   ])
 
  AC_MSG_CHECKING([rrdtool version])
@@ -87,10 +89,4 @@
   if test "$ac_cv_rrdversion" = yes; then
     AC_DEFINE(HAVE_RRD_12X, 1, [Whether you have rrd_verion])
   fi 
-
-  PHP_ADD_LIBRARY_WITH_PATH(rrd, $RRDTOOL_LIBDIR, RRDTOOL_SHARED_LIBADD)
-
-  PHP_NEW_EXTENSION(rrdtool, rrdtool.c, $ext_shared)
-  PHP_SUBST(RRDTOOL_SHARED_LIBADD)
-  AC_DEFINE(HAVE_RRDTOOL, 1, [ ])
 fi
