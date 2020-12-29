--- config.m4.orig	2020-11-24 11:10:57 UTC
+++ config.m4
@@ -184,6 +184,9 @@ AC_DEFUN([PHP_GD_XPM],[
 AC_DEFUN([PHP_GD_FREETYPE2],[
   if test "$PHP_FREETYPE_DIR" != "no"; then
 
+    AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
+
+    AC_MSG_CHECKING([for freetype])
     for i in $PHP_FREETYPE_DIR /usr/local /usr; do
       if test -f "$i/bin/freetype-config"; then
         FREETYPE2_DIR=$i
@@ -192,13 +195,20 @@ AC_DEFUN([PHP_GD_FREETYPE2],[
       fi
     done
 
-    if test -z "$FREETYPE2_DIR"; then
+    if test -n "$FREETYPE2_CONFIG"; then
+      FREETYPE2_CFLAGS=`$FREETYPE2_CONFIG --cflags`
+      FREETYPE2_LIBS=`$FREETYPE2_CONFIG --libs`
+      AC_MSG_RESULT([found in $FREETYPE2_DIR])
+    elif test "$PKG_CONFIG" != "no" && $PKG_CONFIG --exists freetype2; then
+      FREETYPE2_DIR=pkg-config
+      FREETYPE2_CFLAGS=`$PKG_CONFIG freetype2 --cflags`
+      FREETYPE2_LIBS=`$PKG_CONFIG freetype2 --libs`
+      AC_MSG_RESULT([found by pkg-config])
+    else
+      AC_MSG_RESULT([not found])
       AC_MSG_ERROR([freetype-config not found.])
     fi
 
-    FREETYPE2_CFLAGS=`$FREETYPE2_CONFIG --cflags`
-    FREETYPE2_LIBS=`$FREETYPE2_CONFIG --libs`
-
     PHP_EVAL_INCLINE($FREETYPE2_CFLAGS)
     PHP_EVAL_LIBLINE($FREETYPE2_LIBS, GD_SHARED_LIBADD)
     AC_DEFINE(HAVE_LIBFREETYPE,1,[ ])
@@ -285,6 +295,7 @@ dnl enable the support in bundled GD library
 
   if test -n "$GD_XPM_DIR"; then
     AC_DEFINE(HAVE_GD_XPM, 1, [ ])
+    AC_DEFINE(HAVE_XPM, 1, [ ])
     GDLIB_CFLAGS="$GDLIB_CFLAGS -DHAVE_XPM"
   fi
 
@@ -347,7 +358,7 @@ if test "$PHP_GD" != "no"; then
 
   if test "$GD_MODULE_TYPE" = "builtin"; then
     PHP_ADD_BUILD_DIR($ext_builddir/libgd)
-    GDLIB_CFLAGS="-I$ext_srcdir/libgd $GDLIB_CFLAGS"
+    GDLIB_CFLAGS="-I../.. -I$ext_srcdir/libgd $GDLIB_CFLAGS"
     GD_HEADER_DIRS="ext/gd/ ext/gd/libgd/"
 
     PHP_TEST_BUILD(foobar, [], [
@@ -355,7 +366,7 @@ if test "$PHP_GD" != "no"; then
     ], [ $GD_SHARED_LIBADD ], [char foobar () {}])
   else
     GD_HEADER_DIRS="ext/gd/"
-    GDLIB_CFLAGS="-I$GD_INCLUDE $GDLIB_CFLAGS"
+    GDLIB_CFLAGS="-I../.. -I$ext_srcdir/libgd $GDLIB_CFLAGS"
     PHP_ADD_INCLUDE($GD_INCLUDE)
     PHP_CHECK_LIBRARY(gd, gdImageCreate, [], [
       AC_MSG_ERROR([GD build test failed. Please check the config.log for details.])
