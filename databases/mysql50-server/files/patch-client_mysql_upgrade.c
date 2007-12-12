--- client/mysql_upgrade.c.orig	2007-11-15 15:06:52.000000000 +0100
+++ client/mysql_upgrade.c	2007-12-12 10:07:23.000000000 +0100
@@ -411,10 +411,6 @@
 
   verbose("Looking for '%s' in: %s", tool_name, tool_path);
 
-  /* Make sure the tool exists */
-  if (my_access(tool_path, F_OK) != 0)
-    die("Can't find '%s'", tool_path);
-
   /*
     Make sure it can be executed
   */
