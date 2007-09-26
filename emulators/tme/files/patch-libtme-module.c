--- libtme/module.c.orig	Wed Jan 26 13:59:24 2005
+++ libtme/module.c	Sun Dec 17 19:11:37 2006
@@ -107,13 +107,14 @@
   FILE *modules_index;
 
   /* pass over the search path environment variables: */
-  for (pass = 0; ++pass <= 2; ) {
+  for (pass = 0; ++pass <= 3; ) {
 
     /* get the next search path environment variable value: */
     search_path = NULL;
     switch (pass) {
     case 1: search_path = getenv("LTDL_LIBRARY_PATH"); break;
     case 2: search_path = getenv(LTDL_SHLIBPATH_VAR); break;
+    case 3: search_path = "%%PREFIX%%/lib"; break;
     default: assert(FALSE);
     }
     if (search_path == NULL) {
