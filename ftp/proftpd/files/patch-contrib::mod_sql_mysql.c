--- contrib/mod_sql_mysql.c.orig	Sun Nov  2 00:30:13 2003
+++ contrib/mod_sql_mysql.c	Sun Nov  2 00:30:23 2003
@@ -134,7 +134,7 @@
 
 #define _MYSQL_PORT "3306"
 
-#include <mysql.h>
+#include <mysql/mysql.h>
 #include "conf.h"
 #include "../contrib/mod_sql.h"
 
