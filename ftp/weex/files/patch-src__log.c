--- src/log.c.orig	Mon Aug 18 11:52:38 2003
+++ src/log.c	Sun Oct  2 11:06:58 2005
@@ -183,7 +183,7 @@
 
 	fp=log_open();
 	for(i=0;i<max_log;i++){
-		fprintf(fp,log_str[i]);
+		fprintf(fp,"%s",log_str[i]);
 		free(log_str[i]);
 	}
 	free(log_str);
