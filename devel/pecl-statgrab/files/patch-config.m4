--- ./config.m4.orig	2006-03-23 18:43:49.000000000 +0000
+++ ./config.m4	2014-05-10 02:12:22.943986950 +0100
@@ -5,12 +5,12 @@
 [  --with-statgrab             Include libstatgrab support])
 
 AC_DEFUN([PHP_STATGRAB_CHECK_VERSION],[
-  PHP_CHECK_LIBRARY(statgrab, get_network_iface_stats,        [AC_DEFINE(HAVE_STATGRAB_09,             1, [ ])], [], [ -L$STATGRAB_DIR/lib $STATGRAB_SHARED_LIBADD ])
+  PHP_CHECK_LIBRARY(statgrab0, get_network_iface_stats,        [AC_DEFINE(HAVE_STATGRAB_09,             1, [ ])], [], [ -L$STATGRAB_DIR/lib $STATGRAB_SHARED_LIBADD ])
 ])
 
 if test "$PHP_STATGRAB" != "no"; then
   SEARCH_PATH="/usr/local /usr $PHP_STATGRAB"
-  SEARCH_FOR="/include/statgrab.h"
+  SEARCH_FOR="/include/statgrab0.h"
   if test -r $PHP_STATGRAB/$SEARCH_FOR; then # path given as parameter
      STATGRAB_DIR=$PHP_STATGRAB
   else # search default path list
@@ -33,7 +33,7 @@
   PHP_CHECK_LIBRARY(devstat, devstat_selectdevs, [PHP_ADD_LIBRARY(devstat,,DEVSTAT_SHARED_LIBADD)])
   CFLAGS="$CFLAGS $DEVSTAT_SHARED_LIBADD"
 
-  LIBNAME=statgrab
+  LIBNAME=statgrab0
   LIBSYMBOL=sg_init
 
   PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
@@ -50,7 +50,7 @@
   PHP_SUBST(STATGRAB_SHARED_LIBADD)
 
   AC_TRY_COMPILE([
-#include <statgrab.h>
+#include <statgrab0.h>
   ], [
 sg_network_iface_stats p;
 p.dup = SG_IFACE_DUPLEX_UNKNOWN;
