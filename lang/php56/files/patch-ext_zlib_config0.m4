--- ext/zlib/config0.m4.orig	2013-12-10 23:31:06.000000000 +0000
+++ ext/zlib/config0.m4	2013-12-13 21:50:25.378258611 +0000
@@ -8,7 +8,7 @@ PHP_ARG_WITH(zlib,for ZLIB support,
 PHP_ARG_WITH(zlib-dir,if the location of ZLIB install directory is defined,
 [  --with-zlib-dir=<DIR>   Define the location of zlib install directory], no, no)
 
-if test "$PHP_ZLIB" != "no" || test "$PHP_ZLIB_DIR" != "no"; then
+if test "$PHP_ZLIB" != "no"; then
   PHP_NEW_EXTENSION(zlib, zlib.c zlib_fopen_wrapper.c zlib_filter.c, $ext_shared)
   PHP_SUBST(ZLIB_SHARED_LIBADD)
   
