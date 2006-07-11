--- config.m4.orig	Wed Apr  5 11:06:00 2006
+++ config.m4	Tue Jul 11 08:20:27 2006
@@ -177,8 +177,7 @@
       ;;
 
     8.1)
-      PHP_ADD_LIBRARY(clntsh, 1, OCI8_SHARED_LIBADD)
-      PHP_ADD_LIBPATH($OCI8_DIR/$OCI8_LIB_DIR, OCI8_SHARED_LIBADD)
+      PHP_ADD_LIBRARY_WITH_PATH(oci8, ., OCI8_SHARED_LIBADD)
 
       PHP_CHECK_LIBRARY(clntsh, OCIEnvCreate,
       [
