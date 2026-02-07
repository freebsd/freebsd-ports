--- ./common.c.orig	Sun Jan  8 21:02:18 2006
+++ ./common.c	Sat May 20 10:00:24 2006
@@ -1646,14 +1646,18 @@
 */
 void COM_InitFilesystem (void)
 {
+	char	*home;
+	char	homepath[MAX_OSPATH];
 	int	i;
 
+	home = getenv("HOME");
+
 // -basedir <path>
 // Overrides the system supplied base directory (under GAMENAME)
 	if ((i = COM_CheckParm("-basedir")) && i + 1 < com_argc)
 		Q_strncpyz (com_basedir, com_argv[i+1], sizeof(com_basedir));
 	else
-		Q_strncpyz (com_basedir, host_parms.basedir, sizeof(com_basedir));
+		Q_strncpyz (com_basedir, DATADIR, sizeof(com_basedir));
 
 	for (i=0 ; i < strlen(com_basedir) ; i++)
 		if (com_basedir[i] == '\\')
@@ -1665,7 +1669,12 @@
 
 	// start up with GAMENAME by default (id1)
 	COM_AddGameDirectory (va("%s/"GAMENAME, com_basedir));
+	if (home != NULL)
+		COM_AddGameDirectory(va("%s/.joequake/"GAMENAME, home));
+
 	COM_AddGameDirectory (va("%s/joequake", com_basedir));
+	if (home != NULL)
+		COM_AddGameDirectory(va("%s/.joequake/joequake", home));
 
 	if (COM_CheckParm("-rogue"))
 		COM_AddGameDirectory (va("%s/rogue", com_basedir));
@@ -1687,4 +1696,11 @@
 // Adds basedir/gamedir as an override game
 	if ((i = COM_CheckParm("-game")) && i + 1 < com_argc)
         	COM_AddGameDirectory (va("%s/%s", com_basedir, com_argv[i+1]));
+
+	if (home != NULL) {
+		Q_snprintfz(homepath, sizeof(homepath), "%s/.joequake/%s", home, com_gamedirname);
+		COM_CreatePath(homepath);
+		Sys_mkdir(homepath);
+		COM_AddGameDirectory(homepath);
+	}
 }
