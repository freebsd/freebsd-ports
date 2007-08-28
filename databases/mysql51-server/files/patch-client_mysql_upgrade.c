--- client/mysql_upgrade.c.orig	Tue Aug 28 11:16:33 2007
+++ client/mysql_upgrade.c	Tue Aug 28 11:22:24 2007
@@ -395,7 +395,6 @@
       path[0]= 0;
     }
   }
-  do
   {
     size_t path_len;
     DBUG_PRINT("enter", ("path: %s", path));
@@ -411,22 +410,14 @@
               path, "", MYF(MY_REPLACE_DIR));
 
     verbose("Looking for '%s' in: %s", tool_name, tool_path);
-
-    /* Make sure the tool exists */
-    if (my_access(tool_path, F_OK) != 0)
-      die("Can't find '%s'", tool_path);
-
-    /*
-      Make sure it can be executed, otherwise try again
-      in higher level directory
-    */
   }
-  while(run_tool(tool_path,
+  if(run_tool(tool_path,
                  &ds_tmp, /* Get output from command, discard*/
                  "--help",
                  "2>&1",
                  IF_WIN("> NUL", "> /dev/null"),
-                 NULL));
+                 NULL))
+      die("Can't run '%s'", tool_path);
 
   dynstr_free(&ds_tmp);
 
