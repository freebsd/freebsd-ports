--- mapm/database.c.orig	2008-04-04 20:05:29.000000000 +0000
+++ mapm/database.c	2008-03-27 21:26:48.000000000 +0000
@@ -45,7 +45,7 @@
     get_one_arg(stoken, sREQUIRED, out_name);
 
     /* force file extension to be ".data" */
-    make_filename(out_name, FORCE_EXTENSION, ".data");
+    make_filename(out_name, FORCE_EXTENSION, WRS(".data"));
 
     /* make a function call to a procedure which connects to the database */
     get_from_database();
