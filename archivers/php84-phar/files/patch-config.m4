--- config.m4.orig	2024-08-17 04:34:39 UTC
+++ config.m4
@@ -35,8 +35,4 @@ if test "$PHP_PHAR" != "no"; then
 
   PHP_INSTALL_HEADERS([ext/phar], [php_phar.h])
 
-  AC_CONFIG_FILES([
-    $ext_dir/phar.1
-    $ext_dir/phar.phar.1
-  ])
 fi
