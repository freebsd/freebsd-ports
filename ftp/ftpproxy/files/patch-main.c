--- main.c.orig	Fri May 11 16:30:04 2001
+++ main.c	Mon Oct 15 21:24:20 2001
@@ -30,7 +30,7 @@
 #include <stdarg.h>
 
 #include <signal.h>
-#include <wait.h>
+#include <sys/wait.h>
 
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -81,7 +81,7 @@
 	config->timeout = 15 * 60;
 	strcpy(config->varname, "PROXY_");
 
-	openlog(program, LOG_PID, LOG_MAIL);
+	openlog(program, LOG_PID, LOG_FTP);
 
 	k = 1;
 	while (k < argc  &&  argv[k][0] == '-'  &&  argv[k][1] != 0) {
