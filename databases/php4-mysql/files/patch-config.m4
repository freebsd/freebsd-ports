--- config.m4.orig	2007-09-16 17:36:59.000000000 +0200
+++ config.m4	2007-09-16 17:37:28.000000000 +0200
@@ -61,6 +61,7 @@
 if test "$PHP_MYSQL" != "no"; then
   AC_DEFINE(HAVE_MYSQL, 1, [Whether you have MySQL])
 
+  AC_LANG_PREPROC(C)
   AC_MSG_CHECKING(for MySQL UNIX socket location)
   if test "$PHP_MYSQL_SOCK" != "no" && test "$PHP_MYSQL_SOCK" != "yes"; then
     MYSQL_SOCK=$PHP_MYSQL_SOCK
