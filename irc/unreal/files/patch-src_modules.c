--- src/modules.c.orig	2016-09-03 19:34:06 UTC
+++ src/modules.c
@@ -183,12 +183,12 @@ void DeleteTempModules(void)
 {
 	char tempbuf[PATH_MAX+1];
 #ifndef _WIN32
-	DIR *fd = opendir("tmp");
+	DIR *fd = opendir("/var/run/ircd/tmp");
 	struct dirent *dir;
 
 	if (!fd) /* Ouch.. this is NOT good!! */
 	{
-		config_error("Unable to open 'tmp' directory: %s, please create one with the appropriate permissions",
+		config_error("Unable to open '/var/run/ircd' directory: %s, please create one with the appropriate permissions",
 			strerror(errno));
 		if (!loop.ircd_booted)
 			exit(7);
@@ -199,19 +199,19 @@ void DeleteTempModules(void)
 	{
 		if (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, ".."))
 			continue;
-		strcpy(tempbuf, "tmp/");
+		strcpy(tempbuf, "/var/run/ircd/tmp/");
 		strcat(tempbuf, dir->d_name);
 		remove(tempbuf);
 	}
 	closedir(fd);
 #else
 	WIN32_FIND_DATA hData;
-	HANDLE hFile = FindFirstFile("tmp/*", &hData);
+	HANDLE hFile = FindFirstFile("/var/run/ircd/tmp/*", &hData);
 	if (hFile != INVALID_HANDLE_VALUE)
 	{
 		if (strcmp(hData.cFileName, ".") || strcmp(hData.cFileName, ".."))
 		{
-			strcpy(tempbuf, "tmp/");
+			strcpy(tempbuf, "/var/run/ircd/tmp/");
 			strcat(tempbuf, hData.cFileName);
 			remove(tempbuf);
 		}
@@ -220,7 +220,7 @@ void DeleteTempModules(void)
 	{
 		if (!strcmp(hData.cFileName, ".") || !strcmp(hData.cFileName, ".."))
 			continue;
-		strcpy(tempbuf, "tmp/");
+		strcpy(tempbuf, "/var/run/ircd/tmp/");
 		strcat(tempbuf, hData.cFileName);
 		remove(tempbuf);
 	}
@@ -329,7 +329,7 @@ char  *Module_Create(char *path_)
 	path = path_;
 
 	
-	tmppath = unreal_mktemp("tmp", unreal_getfilename(path));
+	tmppath = unreal_mktemp("/var/run/ircd/tmp", unreal_getfilename(path));
 	if (!tmppath)
 		return "Unable to create temporary file!";
 #ifndef _WIN32
