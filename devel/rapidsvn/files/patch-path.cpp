--- src/svncpp/path.cpp.orig	Sat Jan  1 14:54:58 2005
+++ src/svncpp/path.cpp	Sat Jan  1 14:55:24 2005
@@ -259,7 +259,7 @@
     Pool pool;
 
     apr_status_t stat = apr_temp_dir_get (&tempdir, pool);
-    if (!APR_STATUS_IS_SUCCESS(stat))
+    if (APR_SUCCESS != stat)
     {
       tempdir = NULL;
     }
