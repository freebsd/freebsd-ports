--- src/msqld/main/main_broker.c.old	Wed Oct 26 22:07:31 2005
+++ src/msqld/main/main_broker.c	Wed Oct 26 22:08:53 2005
@@ -1391,7 +1391,7 @@
 
 	if (*confFile == 0)
 	{
-		snprintf(confFile,sizeof(confFile),"%s/msql.conf", INST_DIR);
+		snprintf(confFile,sizeof(confFile),"%s/etc/msql3/msql.conf", INST_DIR);
 	}
 	printf("\tLoading configuration from '%s'.\n",confFile);
 	configLoadFile(confFile);
