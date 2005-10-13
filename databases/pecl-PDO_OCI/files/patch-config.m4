--- config.m4.orig	Wed Jul 27 05:48:08 2005
+++ config.m4	Mon Oct 10 10:56:17 2005
@@ -106,7 +106,7 @@
       ;;
 
     8.1)
-      PHP_ADD_LIBRARY(clntsh, 1, PDO_OCI_SHARED_LIBADD)
+      PHP_ADD_LIBRARY_WITH_PATH(oci8, ., PDO_OCI_SHARED_LIBADD)
       ;;
 
     9.0)
