--- config-lib.m4.orig	2010-04-20 10:09:36.000000000 +0900
+++ config-lib.m4	2010-06-13 13:01:53.000000000 +0900
@@ -70,7 +70,7 @@
     else
       AC_MSG_ERROR([Can't find LIBPNG headers under "$PHP_PNG_DIR"])
     fi
-  else
+  elif test "$PHP_PNG_DIR" = "yes"; then
     for i in /usr/local /usr; do
       if test -f "$i/include/libpng/png.h"; then
 	AC_DEFINE(HAVE_PNG,1,[ ])
@@ -115,7 +115,7 @@
     else
       AC_MSG_ERROR([Can't find GIFLIB headers under "$PHP_GIF_DIR"])
     fi
-  else
+  elif test "$PHP_GIF_DIR" = "yes"; then
     for i in /usr/local /usr; do
       if test -f "$i/include/giflib/gif_lib.h"; then
 	AC_DEFINE(HAVE_GIF,1,[ ])
