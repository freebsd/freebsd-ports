--- config.m4.orig	Wed Jul  7 10:02:27 2004
+++ config.m4	Mon Jul 19 23:52:07 2004
@@ -47,7 +47,9 @@
     PHP_CHECK_LIBRARY(mysqlclient, mysql_stmt_field_count,
     [ ],[
 		AC_MSG_ERROR([MySQLI doesn't support versions < 4.1.3 (for MySQL 4.1.x) and < 5.0.1 for (MySQL 5.0.x) anymore. Please update your libraries.])
-	],[])
+    ],[
+      $MYSQLI_LIBLINE
+    ])
   ],[
     AC_MSG_ERROR([wrong mysql library version or lib not found. Check config.log for more information.])
   ],[
