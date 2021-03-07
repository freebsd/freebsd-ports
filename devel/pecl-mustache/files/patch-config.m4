--- config.m4.orig	2020-11-13 03:48:50 UTC
+++ config.m4
@@ -70,7 +70,6 @@ if test "$PHP_MUSTACHE" != "no"; then
 
   AC_DEFINE(HAVE_MUSTACHE, 1, [Whether you have mustache support])
   PHP_REQUIRE_CXX()
-  PHP_ADD_LIBRARY(stdc++, 1, MUSTACHE_SHARED_LIBADD)
 
   PHP_MUSTACHE_ADD_SOURCES([
     php_mustache.cpp
