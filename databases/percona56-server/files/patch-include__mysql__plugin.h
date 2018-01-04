--- include/mysql/plugin.h.orig
+++ include/mysql/plugin.h
@@ -51,6 +51,7 @@
 typedef void * MYSQL_PLUGIN;
 
 #include <mysql/services.h>
+#include <my_global.h>
 
 #define MYSQL_XIDDATASIZE 128
 /**
