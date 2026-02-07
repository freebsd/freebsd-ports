--- mapm/database.c.orig	1993-02-09 16:35:02 UTC
+++ mapm/database.c
@@ -45,7 +45,7 @@ command import()
     get_one_arg(stoken, sREQUIRED, out_name);
 
     /* force file extension to be ".data" */
-    make_filename(out_name, FORCE_EXTENSION, ".data");
+    make_filename(out_name, FORCE_EXTENSION, WRS(".data"));
 
     /* make a function call to a procedure which connects to the database */
     get_from_database();
