--- contrib/sqlreply/c/michal.c.orig	2011-05-19 14:55:52.000000000 -0300
+++ contrib/sqlreply/c/michal.c	2011-05-19 14:51:33.000000000 -0300
@@ -13,8 +13,8 @@
 #else
 #include <stdio.h>
 #include <time.h>
-#include <mysql/mysql.h>
-#include <mysql/mysqld_error.h>
+#include <mysql.h>
+#include <mysqld_error.h>
 #include <sys/types.h>
 #include <unistd.h>
 #endif
