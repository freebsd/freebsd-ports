--- contrib/mod_sql_mysql.c.orig	2007-07-05 10:34:43.000000000 -0800
+++ contrib/mod_sql_mysql.c	2007-07-05 10:42:05.000000000 -0800
@@ -595,7 +595,7 @@
   }
 
   if (!conn_pool) {
-    pr_log_pri(PR_LOG_WARNING, "warning: the mod_sql_mysql module has not been
+    pr_log_pri(PR_LOG_WARNING, "warning: the mod_sql_mysql module has not been"
       "properly intialized.  Please make sure your --with-modules configure "
       "option lists mod_sql *before* mod_sql_mysql, and recompile.");
 
