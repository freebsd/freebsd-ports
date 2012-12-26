--- src/gcompris/gcompris.c.orig	2012-10-27 03:24:09.000000000 +0400
+++ src/gcompris/gcompris.c	2012-11-26 21:38:50.000000000 +0400
@@ -1332,7 +1332,7 @@
 /* Display the directory value we have */
 static void display_property_dirs()
 {
-  exec_prefix = gbr_find_exe_dir(NULL);
+  exec_prefix = gbr_find_exe_dir("%%PREFIX%%");
   printf("exec_prefix              = %s\n", (exec_prefix==NULL ? "NONE" : exec_prefix));
 
   printf("package_data_dir         = %s\n", properties->package_data_dir);
