--- src/log_mysql_p.h.orig	Sun Feb 29 18:49:28 2004
+++ src/log_mysql_p.h	Tue Sep 12 07:10:35 2006
@@ -2,6 +2,7 @@
 #define __LOG_MYSQL_P_H__ 1
 
 #include <mysql.h>
+#include <my_globals.h>
 
 #ifdef MYSQL_VERSION_ID
 # if MYSQL_VERSION_ID < 32224
