--- config.m4.orig	Thu Feb 16 03:03:13 2006
+++ config.m4	Wed Feb  7 15:00:58 2007
@@ -145,7 +145,6 @@
       ;;
 
     8.1)
-      PHP_ADD_LIBRARY(clntsh, 1, PDO_OCI_SHARED_LIBADD)
       ;;
 
     9.0)
@@ -163,7 +162,7 @@
       ;;
   esac
 
-  PHP_ADD_LIBPATH($PDO_OCI_LIB_DIR, PDO_OCI_SHARED_LIBADD)
+  PHP_ADD_LIBRARY_WITH_PATH(oci8, ., PDO_OCI_SHARED_LIBADD)
 
   PHP_CHECK_LIBRARY(clntsh, OCIEnvCreate,
   [
