--- src/wget-log.c.orig	Sat Apr  2 23:05:09 2005
+++ src/wget-log.c	Sat Apr  2 23:31:55 2005
@@ -58,11 +58,13 @@
 static int
 wget_log_process_line (GwgetData *gwgetdata)
 {
-	if (gwgetdata->line == NULL)
-		return 0;
-
 	gchar *p;
 	struct stat file_stat;
+	char *sName;
+	int iL;
+
+	if (gwgetdata->line == NULL)
+		return 0;
 
 	switch (gwgetdata->state) {
 	case DL_NOT_CONNECTED:
@@ -72,10 +74,10 @@
 		 * filesystem filename and set gwgetdata->filename
 		 */
 		if (strstr(gwgetdata->line,"           => `")) {
-			int iL = strlen(gwgetdata->line);
+			iL = strlen(gwgetdata->line);
 			gwgetdata->line[iL-1] = 0; // Chop the final ' 
 
-			char *sName = gwgetdata->line;
+			sName = gwgetdata->line;
 			/*
 			 * Now sName contains the whole pathname. No filename can
 			 * contain '/' so the following search for the last component
@@ -272,11 +274,14 @@
 
 void
 wget_log_read_log_line(GwgetData *gwgetdata) {
+	char c;
+	int iRes, iBlockCount, iWritePos;
+	gchar *buffer;	
+
 	g_free(gwgetdata->line);
 	gwgetdata->line = NULL;
-
-	char c;
-	int iRes = read(gwgetdata->log_fd,&c,1);
+       	
+	iRes = read(gwgetdata->log_fd,&c,1);
 
 	if (iRes < 1) {
 		/*
@@ -286,9 +291,9 @@
 		return;
 	}
 
-	int iBlockCount = 1;
-	gchar *buffer = g_malloc(sizeof(gchar)*(iBlockCount*BLOCK_SIZE));
-	int iWritePos = 0;
+	iBlockCount = 1;
+	buffer = g_malloc(sizeof(gchar)*(iBlockCount*BLOCK_SIZE));
+	iWritePos = 0;
 		
 	buffer[iWritePos++] = c;
 	while (c != '\n') {
