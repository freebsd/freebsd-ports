--- src/msqld/main/acl.c.old	Tue May  4 17:41:51 2004
+++ src/msqld/main/acl.c	Tue May  4 17:42:14 2004
@@ -304,7 +304,7 @@
 	/*
 	** Open the acl file
 	*/
-	(void)snprintf(path,MSQL_PATH_LEN,"%s/msql.acl", 
+	(void)snprintf(path,MSQL_PATH_LEN,"%s/etc/msql3/msql.acl", 
 		(char *)configGetCharEntry("general", "inst_dir"));
 	fp = fopen(path,"r");
 	if (!fp)
