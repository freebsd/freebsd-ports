--- src/msqladmin/msqladmin.c.orig	Mon Jan 13 10:16:02 1997
+++ src/msqladmin/msqladmin.c	Sun Jan 19 14:05:53 1997
@@ -257,7 +257,7 @@
 		printf("\tTarget platform \t%s\n\n",TARGET);
 
 		printf("Configuration Details :-\n\n");
-		printf("\tDefault config file\t%s/msql.conf\n",INST_DIR);
+		printf("\tDefault config file\t%s/etc/msql3/msql.conf\n",INST_DIR);
 		printf("\tTCP socket         \t%d\n", 
 			msqlGetIntConf("tcp_port"));
 		printf("\tUNIX socket        \t%s\n", 
