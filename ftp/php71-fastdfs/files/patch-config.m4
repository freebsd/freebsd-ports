--- config.m4.orig	2016-08-08 07:17:50 UTC
+++ config.m4
@@ -7,7 +7,7 @@ if test "$PHP_FASTDFS_CLIENT" != "no"; t
   PHP_SUBST(FASTDFS_CLIENT_SHARED_LIBADD)
 
   if test -z "$ROOT"; then
-	ROOT=/usr
+	ROOT=/usr/local
   fi
 
   PHP_ADD_INCLUDE($ROOT/include/fastcommon)
