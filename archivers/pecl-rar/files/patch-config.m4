--- config.m4.orgi	2013-05-28 16:35:29.000000000 +0800
+++ config.m4	2013-05-28 16:35:47.000000000 +0800
@@ -27,6 +27,6 @@
   PHP_REQUIRE_CXX()
   PHP_ADD_LIBRARY_WITH_PATH(stdc++, "", RAR_SHARED_LIBADD)
 
-  PHP_NEW_EXTENSION(rar, rar.c rar_error.c rararch.c rarentry.c rar_stream.c rar_navigation.c $unrar_sources, $ext_shared,,-DRARDLL -DGUI -DSILENT -Wno-write-strings -Wno-logical-op-parentheses -I@ext_srcdir@/unrar)  
+  PHP_NEW_EXTENSION(rar, rar.c rar_error.c rararch.c rarentry.c rar_stream.c rar_navigation.c $unrar_sources, $ext_shared,,-DRARDLL -DGUI -DSILENT -Wno-write-strings -I@ext_srcdir@/unrar)  
   PHP_ADD_BUILD_DIR($ext_builddir/unrar)  
 fi
