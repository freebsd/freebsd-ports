--- config.m4.orig	2013-10-14 15:30:44 UTC
+++ config.m4
@@ -27,6 +27,6 @@ if test "$PHP_RAR" != "no"; then
   PHP_REQUIRE_CXX()
   PHP_ADD_LIBRARY_WITH_PATH(stdc++, "", RAR_SHARED_LIBADD)
 
-  PHP_NEW_EXTENSION(rar, rar.c rar_error.c rararch.c rarentry.c rar_stream.c rar_navigation.c $unrar_sources, $ext_shared,,-DRARDLL -DGUI -DSILENT -Wno-write-strings -Wno-logical-op-parentheses -I@ext_srcdir@/unrar)  
+  PHP_NEW_EXTENSION(rar, rar.c rar_error.c rararch.c rarentry.c rar_stream.c rar_navigation.c $unrar_sources, $ext_shared,,-DRARDLL -DGUI -DSILENT -Wno-write-strings -I@ext_srcdir@/unrar)  
   PHP_ADD_BUILD_DIR($ext_builddir/unrar)  
 fi
