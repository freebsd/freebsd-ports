--- common.c.orig	Tue Oct 24 12:50:11 2006
+++ common.c	Tue Dec 19 14:11:31 2006
@@ -931,14 +931,18 @@
 }
 
 void FS_InitFilesystem (void) {
+	char	*home;
+	char	homepath[MAX_OSPATH];
 	int i;
 
+	home = getenv("HOME");
+
 	// -basedir <path>
 	// Overrides the system supplied base directory (under id1)
 	if ((i = COM_CheckParm ("-basedir")) && i < com_argc - 1)
 		strlcpy (com_basedir, com_argv[i + 1], sizeof(com_basedir));
 	else
-		Sys_getcwd(com_basedir, sizeof(com_basedir) - 1); // FIXME strlcpy (com_basedir, sizeof(com_basedir, "."); ?
+		strlcpy(com_basedir, DATADIR, sizeof(com_basedir) - 1);
 
 	for (i = 0; i < (int) strlen(com_basedir); i++)
 		if (com_basedir[i] == '\\')
@@ -950,9 +954,14 @@
 
 	// start up with id1 by default
 	FS_AddGameDirectory ( va("%s/id1", com_basedir) );
-	FS_AddGameDirectory ( va("%s/ezquake", com_basedir) );
+	if (home != NULL)
+		FS_AddGameDirectory(va("%s/.ezquake/id1", home));
 	FS_AddGameDirectory ( va("%s/qw", com_basedir) );
 
+	FS_AddGameDirectory ( va("%s/ezquake", com_basedir) );
+	if (home != NULL)
+		FS_AddGameDirectory(va("%s/.ezquake/ezquake", home));
+
 	// any set gamedirs will be freed up to here
 	com_base_searchpaths = com_searchpaths;
 
@@ -971,6 +980,13 @@
 		if( UserdirSet )
 #endif
 			FS_SetGamedir("qw");
+	}
+
+	if (home != NULL) {
+		snprintf(homepath, sizeof(homepath), "%s/.ezquake/%s", home, com_gamedirfile);
+		COM_CreatePath(homepath);
+		Sys_mkdir(homepath);
+		FS_AddGameDirectory(homepath);
 	}
 }
 
