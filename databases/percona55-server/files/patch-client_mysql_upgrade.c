--- client/mysql_upgrade.c.orig	2008-01-29 22:42:00.000000000 +0100
+++ client/mysql_upgrade.c	2008-02-14 08:29:52.000000000 +0100
@@ -427,10 +427,6 @@
 
   verbose("Looking for '%s' in: %s", tool_name, tool_path);
 
-  /* Make sure the tool exists */
-  if (my_access(tool_path, F_OK) != 0)
-    die("Can't find '%s'", tool_path);
-
   /*
     Make sure it can be executed
   */
