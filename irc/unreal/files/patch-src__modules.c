--- ./src/modules.c.orig	2013-11-24 20:24:26.000000000 +0100
+++ ./src/modules.c	2014-05-23 00:34:33.000000000 +0200
@@ -183,12 +183,12 @@
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
@@ -199,19 +199,19 @@
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
@@ -220,7 +220,7 @@
 	{
 		if (!strcmp(hData.cFileName, ".") || !strcmp(hData.cFileName, ".."))
 			continue;
-		strcpy(tempbuf, "tmp/");
+		strcpy(tempbuf, "%%RUNDIR%%/tmp/");
 		strcat(tempbuf, hData.cFileName);
 		remove(tempbuf);
 	}
@@ -329,7 +329,7 @@
 	path = path_;
 
 	
-	tmppath = unreal_mktemp("tmp", unreal_getfilename(path));
+	tmppath = unreal_mktemp("%%RUNDIR%%/tmp", unreal_getfilename(path));
 	if (!tmppath)
 		return "Unable to create temporary file!";
 #ifndef _WIN32
