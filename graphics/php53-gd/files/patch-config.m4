--- config.m4.orig	2013-12-10 20:04:57.000000000 +0100
+++ config.m4	2013-12-24 21:07:17.000000000 +0100
@@ -162,7 +162,7 @@
   if test "$PHP_FREETYPE_DIR" != "no"; then
 
     for i in $PHP_FREETYPE_DIR /usr/local /usr; do
-      if test -f "$i/include/freetype2/freetype/freetype.h"; then
+      if test -f "$i/include/freetype2/freetype.h"; then
         FREETYPE2_DIR=$i
         FREETYPE2_INC_DIR=$i/include/freetype2
         break
@@ -210,7 +210,7 @@
     ],[
       AC_MSG_ERROR([Problem with libt1.(a|so). Please check config.log for more information.])
     ],[
-      -L$GD_T1_DIR/$PHP_LIBDIR
+      -L$GD_T1_DIR/$PHP_LIBDIR -lm
     ])
   fi
 ])
