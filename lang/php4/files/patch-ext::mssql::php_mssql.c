--- ext/mssql/php_mssql.c.orig	Wed Apr 21 01:31:39 2004
+++ ext/mssql/php_mssql.c	Tue Jun  8 15:19:55 2004
@@ -336,7 +336,7 @@
 	dbsetlogintime(MS_SQL_G(connect_timeout));
 	if (MS_SQL_G(timeout) < 0) MS_SQL_G(timeout) = 60;
 	dbsettime(MS_SQL_G(timeout));
-	dbsetmaxprocs((SHORT)MS_SQL_G(max_procs));
+	dbsetmaxprocs((TDS_SHORT)MS_SQL_G(max_procs));
 
 	return SUCCESS;
 }
