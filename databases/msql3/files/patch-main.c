--- src/msqld/main/main.c.old	Tue May  4 17:21:52 2004
+++ src/msqld/main/main.c	Tue May  4 17:22:26 2004
@@ -1033,7 +1033,7 @@
 
 	if (*confFile == 0)
 	{
-		snprintf(confFile,sizeof(confFile),"%s/msql.conf", INST_DIR);
+		snprintf(confFile,sizeof(confFile),"%s/etc/msql3/msql.conf", INST_DIR);
 	}
 	printf("\tLoading configuration from '%s'.\n",confFile);
 	configLoadFile(confFile);
