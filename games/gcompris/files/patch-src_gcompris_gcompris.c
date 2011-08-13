--- src/gcompris/gcompris.c.orig	2011-02-22 23:55:08.000000000 +0300
+++ src/gcompris/gcompris.c	2011-08-12 10:54:59.000000000 +0400
@@ -1295,7 +1295,7 @@
       g_error_free (error);
     }
 
-  exec_prefix = gbr_find_exe_dir(NULL);
+  exec_prefix = gbr_find_exe_dir("%%PREFIX%%");
   g_warning("exec_prefix %s\n", (exec_prefix==NULL ? "NONE" : exec_prefix));
 
   {
