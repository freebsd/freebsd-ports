--- src/modules.c	Wed Oct 27 20:45:27 2004
+++ src/modules.c	Mon Feb  7 04:01:47 2005
@@ -90,12 +90,12 @@
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
@@ -106,7 +106,7 @@
 	{
 		if (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, ".."))
 			continue;
-		strcpy(tempbuf, "tmp/");
+		strcpy(tempbuf, "%%RUNDIR%%/tmp/");
 		strcat(tempbuf, dir->d_name);
 		remove(tempbuf);
 	}
@@ -118,7 +118,7 @@
 	{
 		if (strcmp(hData.cFileName, ".") || strcmp(hData.cFileName, ".."))
 		{
-			strcpy(tempbuf, "tmp/");
+			strcpy(tempbuf, "%%RUNDIR%%/tmp/");
 			strcat(tempbuf, hData.cFileName);
 			remove(tempbuf);
 		}
@@ -127,7 +127,7 @@
 	{
 		if (!strcmp(hData.cFileName, ".") || !strcmp(hData.cFileName, ".."))
 			continue;
-		strcpy(tempbuf, "tmp/");
+		strcpy(tempbuf, "%%RUNDIR%%/tmp/");
 		strcat(tempbuf, hData.cFileName);
 		remove(tempbuf);
 	}
@@ -200,7 +200,7 @@
 	path = path_;
 
 	
-	tmppath = unreal_mktemp("tmp", unreal_getfilename(path));
+	tmppath = unreal_mktemp("%%RUNDIR%%/tmp", unreal_getfilename(path));
 	if (!tmppath)
 		return "Unable to create temporary file!";
 	if(!strchr(path, '/'))
