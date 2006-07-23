--- common.c.orig	Wed Jan  7 00:39:44 2004
+++ common.c	Tue Jan 31 14:39:05 2006
@@ -652,16 +652,10 @@
 //The filename will be prefixed by com_basedir
 qboolean COM_WriteFile (char *filename, void *data, int len) {
 	FILE *f;
-	char name[MAX_OSPATH];
 
-	Q_snprintfz (name, sizeof(name), "%s/%s", com_basedir, filename);
-
-	if (!(f = fopen (name, "wb"))) {
-		COM_CreatePath (name);
-		if (!(f = fopen (name, "wb")))
-			return false;
-	}
-	Sys_Printf ("COM_WriteFile: %s\n", name);
+	if (!(f = fopen (filename, "wb")))
+		return false;
+	Sys_Printf ("COM_WriteFile: %s\n", filename);
 	fwrite (data, 1, len, f);
 	fclose (f);
 	return true;
@@ -670,6 +664,7 @@
 //Only used for CopyFile and download
 
 
+#if 0
 #define _MAX_SUBSIRS	8
 void COM_CreatePath (char *path) {
 	char *slash = NULL;
@@ -699,6 +694,22 @@
 		path[slash_indices[i]] = '/';
 	}
 }
+#else
+void COM_CreatePath (char *path)
+{
+	char	*ofs;
+
+	for (ofs = path+1 ; *ofs ; ofs++)
+	{
+		if (*ofs == '/')
+		{       // create the directory
+			*ofs = 0;
+			Sys_mkdir (path);
+			*ofs = '/';
+		}
+	}
+}
+#endif
 
 //Copies a file over from the net to the local cache, creating any directories
 //needed.  This is for the convenience of developers using ISDN from home.
@@ -976,7 +987,7 @@
 
 	sprintf (com_gamedir, "%s/%s", com_basedir, dir);
 
-	if (!strcmp(dir, "id1") || !strcmp(dir, "qw") || !strcmp(dir, "fuhquake"))	
+	if (!strcmp(dir, "id1") || !strcmp(dir, "fuhquake"))
 		return;
 
 	// add the directory to the search path
@@ -999,14 +1010,17 @@
 }
 
 void FS_InitFilesystem (void) {
+	char	*home, homepath[MAX_OSPATH];
 	int		i;
 
+	home = getenv("HOME");
+
 	// -basedir <path>
 	// Overrides the system supplied base directory (under id1)
 	if ((i = COM_CheckParm ("-basedir")) && i < com_argc - 1)
 		Q_strncpyz (com_basedir, com_argv[i + 1], sizeof(com_basedir));
 	else
-		getcwd(com_basedir, sizeof(com_basedir) - 1);
+		Q_strncpyz(com_basedir, DATADIR, sizeof(com_basedir));
 
 	for (i = 0; i < strlen(com_basedir); i++)
 		if (com_basedir[i] == '\\')
@@ -1018,8 +1032,13 @@
 
 	// start up with id1 by default
 	FS_AddGameDirectory ( va("%s/id1", com_basedir) );
+
+	if (home != NULL) {
+		Q_snprintfz(homepath, sizeof(homepath), "%s/.fuhquake/id1", home, com_gamedirfile);
+		FS_AddGameDirectory(homepath);
+	}
+
 	FS_AddGameDirectory ( va("%s/fuhquake", com_basedir) );	
-	FS_AddGameDirectory ( va("%s/qw", com_basedir) );
 
 	// any set gamedirs will be freed up to here
 	com_base_searchpaths = com_searchpaths;
@@ -1029,6 +1048,13 @@
 		i = COM_CheckParm ("+gamedir");
 	if (i && i < com_argc - 1)
 		FS_SetGamedir (com_argv[i + 1]);
+
+	if (home != NULL) {
+		Q_snprintfz(homepath, sizeof(homepath), "%s/.fuhquake/%s", home, com_gamedirfile);
+		COM_CreatePath(homepath);
+		Sys_mkdir(homepath);
+		FS_AddGameDirectory(homepath);
+	}
 }
 
 /*
