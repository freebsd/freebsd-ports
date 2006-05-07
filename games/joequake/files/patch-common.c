--- common.c.orig	Sat Dec  3 19:45:26 2005
+++ common.c	Tue Jan 31 15:03:09 2006
@@ -1634,14 +1634,18 @@
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
@@ -1653,6 +1657,12 @@
 
 	// start up with GAMENAME by default (id1)
 	COM_AddGameDirectory (va("%s/"GAMENAME, com_basedir));
+
+	if (home != NULL) {
+		Q_snprintfz(homepath, sizeof(homepath), "%s/.joequake/"GAMENAME, home);
+		COM_AddGameDirectory(homepath);
+	}
+
 	COM_AddGameDirectory (va("%s/joequake", com_basedir));
 
 	if (COM_CheckParm("-rogue"))
@@ -1675,4 +1685,11 @@
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
