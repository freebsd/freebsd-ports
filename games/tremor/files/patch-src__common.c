--- ./src/common.c.orig	Thu Nov 10 09:56:53 2005
+++ ./src/common.c	Tue May 16 15:00:44 2006
@@ -1769,14 +1769,18 @@
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
 	if ((i = COM_CheckParm ("-basedir")) && i < com_argc-1)
 		Q_strncpyz (com_basedir, com_argv[i+1], sizeof(com_basedir));
 	else
-		Q_strncpyz (com_basedir, host_parms.basedir, sizeof(com_basedir));
+		Q_strncpyz (com_basedir, DATADIR, sizeof(com_basedir));
 
 	for (i=0 ; i < strlen(com_basedir) ; i++)
 		if (com_basedir[i] == '\\')
@@ -1788,7 +1792,11 @@
 
 	// start up with GAMENAME by default (id1)
 	COM_AddGameDirectory (va("%s/"GAMENAME, com_basedir));
-	COM_AddGameDirectory (va("%s/base", com_basedir));	// JT021305 - use base as default GAMENAME
+	if (home != NULL)
+		COM_AddGameDirectory(va("%s/.tremor/"GAMENAME, home));
+	COM_AddGameDirectory (va("%s/tremor", com_basedir));	// JT021305 - use base as default GAMENAME
+	if (home != NULL)
+		COM_AddGameDirectory(va("%s/.tremor/tremor", home));
 
 	if (COM_CheckParm("-rogue"))
 		COM_AddGameDirectory (va("%s/rogue", com_basedir));
@@ -1807,4 +1815,12 @@
 // Adds basedir/gamedir as an override game
 	if ((i = COM_CheckParm("-game")) && i < com_argc-1)
         	COM_AddGameDirectory (va("%s/%s", com_basedir, com_argv[i+1]));
+
+	if (home != NULL) {
+		Q_snprintfz(homepath, sizeof(homepath), "%s/.tremor/%s",
+		    home, com_gamedirname);
+		COM_CreatePath(homepath);
+		Sys_mkdir(homepath);
+		COM_AddGameDirectory(homepath);
+	}
 }
