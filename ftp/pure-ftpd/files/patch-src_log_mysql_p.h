--- src/log_mysql_p.h.orig	Mon Sep 11 11:57:13 2006
+++ src/log_mysql_p.h	Mon Sep 11 11:57:23 2006
@@ -3,6 +3,8 @@
 
 #include <mysql.h>
 
+typedef unsigned long	ulong;
+
 #ifdef MYSQL_VERSION_ID
 # if MYSQL_VERSION_ID < 32224
 #  define mysql_field_count(X) mysql_num_fields(X)
