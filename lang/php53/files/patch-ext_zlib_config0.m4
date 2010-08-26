--- ext/zlib/config0.m4.orig	2010-08-26 13:19:52.000000000 +0200
+++ ext/zlib/config0.m4	2010-08-26 13:20:11.000000000 +0200
@@ -8,7 +8,7 @@
 PHP_ARG_WITH(zlib-dir,if the location of ZLIB install directory is defined,
 [  --with-zlib-dir=<DIR>   Define the location of zlib install directory], no, no)
 
-if test "$PHP_ZLIB" != "no" || test "$PHP_ZLIB_DIR" != "no"; then
+if test "$PHP_ZLIB" != "no"; then
   PHP_NEW_EXTENSION(zlib, zlib.c zlib_fopen_wrapper.c zlib_filter.c, $ext_shared)
   PHP_SUBST(ZLIB_SHARED_LIBADD)
   
