--- ./libs/console/server.c.orig	Tue Jan 27 02:23:36 2004
+++ ./libs/console/server.c	Sun Dec 17 15:53:42 2006
@@ -70,7 +70,7 @@
 
 #include "compat.h"
 
-static console_data_t con_data;
+console_data_t con_data;
 
 static QFile  *log_file;
 static cvar_t *sv_logfile;
