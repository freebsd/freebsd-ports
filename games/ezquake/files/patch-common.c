--- ./common.c.orig	Tue Apr 18 17:59:55 2006
+++ ./common.c	Wed Aug 30 18:01:03 2006
@@ -1387,14 +1387,18 @@
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
-		getcwd(com_basedir, sizeof(com_basedir) - 1);
+		strlcpy(com_basedir, DATADIR, sizeof(com_basedir) - 1);
 
 	for (i = 0; i < strlen(com_basedir); i++)
 		if (com_basedir[i] == '\\')
@@ -1406,8 +1410,16 @@
 
 	// start up with id1 by default
 	FS_AddGameDirectory ( va("%s/id1", com_basedir) );
-	FS_AddGameDirectory ( va("%s/ezquake", com_basedir) );	
+	if (home != NULL)
+		FS_AddGameDirectory(va("%s/.ezquake/id1", home));
+
 	FS_AddGameDirectory ( va("%s/qw", com_basedir) );
+	if (home != NULL)
+		FS_AddGameDirectory(va("%s/.ezquake/qw", home));
+
+	FS_AddGameDirectory ( va("%s/ezquake", com_basedir) );	
+	if (home != NULL)
+		FS_AddGameDirectory(va("%s/.ezquake/ezquake", home));
 
 	// any set gamedirs will be freed up to here
 	com_base_searchpaths = com_searchpaths;
@@ -1426,6 +1438,13 @@
 	{ 
 		if( UserdirSet ) 
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
 
