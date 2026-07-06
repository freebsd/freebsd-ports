--- config.m4.orig	2025-07-01 21:58:05 UTC
+++ config.m4
@@ -32,8 +32,4 @@ if test "$PHP_PHAR" != "no"; then
   PHP_ADD_EXTENSION_DEP(phar, spl)
   PHP_ADD_MAKEFILE_FRAGMENT
 
-  AC_CONFIG_FILES([
-    $ext_dir/phar.1
-    $ext_dir/phar.phar.1
-  ])
 fi
