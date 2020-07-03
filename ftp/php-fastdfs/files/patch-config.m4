--- config.m4.orig	2019-12-30 23:36:03 UTC
+++ config.m4
@@ -10,7 +10,7 @@ if test "$PHP_FASTDFS_CLIENT" != "no"; t
 	ROOT=/usr
   fi
 
-  PHP_ADD_INCLUDE($ROOT/local/include)
+  PHP_ADD_INCLUDE($ROOT/include)
 
   PHP_ADD_LIBRARY_WITH_PATH(fastcommon, $ROOT/lib, FASTDFS_CLIENT_SHARED_LIBADD)
   PHP_ADD_LIBRARY_WITH_PATH(fdfsclient, $ROOT/lib, FASTDFS_CLIENT_SHARED_LIBADD)
