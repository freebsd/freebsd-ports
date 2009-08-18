--- src/modules.c	2009-04-13 13:03:58.000000000 +0200
+++ src/modules.c	2009-08-18 16:29:34.000000000 +0200
@@ -177,12 +177,12 @@
 {
 	char tempbuf[PATH_MAX+1];
 #ifndef _WIN32
-	DIR *fd = opendir("tmp");
+	DIR *fd = opendir("%%RUNDIR%%/tmp");
 	struct dirent *dir;
 
 	if (!fd) /* Ouch.. this is NOT good!! */
 	{
-		config_error("Unable to open 'tmp' directory: %s, please create one with the appropriate permissions",
+		config_error("Unable to open '%%RUNDIR%%' directory: %s, please create one with the appropriate permissions",
 			strerror(errno));
 		if (!loop.ircd_booted)
 			exit(7);
@@ -193,19 +193,19 @@
 	{
 		if (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, ".."))
 			continue;
-		strcpy(tempbuf, "tmp/");
+		strcpy(tempbuf, "%%RUNDIR%%/tmp/");
 		strcat(tempbuf, dir->d_name);
 		remove(tempbuf);
 	}
 	closedir(fd);
 #else
 	WIN32_FIND_DATA hData;
-	HANDLE hFile = FindFirstFile("tmp/*", &hData);
+	HANDLE hFile = FindFirstFile("%%RUNDIR%%/tmp/*", &hData);
 	if (hFile != INVALID_HANDLE_VALUE)
 	{
 		if (strcmp(hData.cFileName, ".") || strcmp(hData.cFileName, ".."))
 		{
-			strcpy(tempbuf, "tmp/");
+			strcpy(tempbuf, "%%RUNDIR%%/tmp/");
 			strcat(tempbuf, hData.cFileName);
 			remove(tempbuf);
 		}
@@ -214,7 +214,7 @@
 	{
 		if (!strcmp(hData.cFileName, ".") || !strcmp(hData.cFileName, ".."))
 			continue;
-		strcpy(tempbuf, "tmp/");
+		strcpy(tempbuf, "%%RUNDIR%%/tmp/");
 		strcat(tempbuf, hData.cFileName);
 		remove(tempbuf);
 	}
