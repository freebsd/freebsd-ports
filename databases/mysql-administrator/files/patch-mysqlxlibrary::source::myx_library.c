--- mysqlxlibrary/source/myx_library.c.orig	Sun Feb 22 03:37:26 2004
+++ mysqlxlibrary/source/myx_library.c	Sun Feb 22 03:34:03 2004
@@ -102,7 +102,10 @@
 
 const char *myx_get_my_cnf_path()
 {
-  return myx_my_cnf_path;
+  if (myx_my_cnf_path == NULL)
+    return "";
+  else
+    return myx_my_cnf_path;
 }
 
 
