--- ./src/common.c.orig	Thu Nov 10 09:51:58 2005
+++ ./src/common.c	Tue May 16 14:33:39 2006
@@ -1820,14 +1820,18 @@
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
 		Q_strcpy (com_basedir, com_argv[i+1]);
 	else
-		Q_strcpy (com_basedir, host_parms. basedir);
+		Q_strcpy (com_basedir, DATADIR);
 
 	for (i=0 ; i < strlen(com_basedir) ; i++)
 	{
@@ -1845,10 +1849,17 @@
 	COM_AddGameDirectory (va("%s/"GAMENAME, com_basedir));
 	Q_strncpy (demodir, "/id1", sizeof(demodir));
 	
+
+	if (home != NULL)
+		COM_AddGameDirectory(va("%s/.demonquake/id1", homepath));
+
 // add demonquake to the path (demonquake)
 	COM_AddGameDirectory (va("%s/"BASENAME, com_basedir));
 	Q_strncpy (demodir, "/demonquake", sizeof(demodir));
 	
+	if (home != NULL)
+		COM_AddGameDirectory(va("%s/.demonquake/demonquake", homepath));
+
 	// reckless (expanded checks):
 	if (COM_CheckParm("-rogue")) {
 		COM_AddGameDirectory (va("%s/rogue", com_basedir));
@@ -1878,6 +1889,15 @@
 	if ((i = COM_CheckParm ("-game")) && i < com_argc-1) {
 		COM_AddGameDirectory (va("%s/%s", com_basedir, com_argv[i+1]));
 		Q_strncpy (demodir, va("/%s", com_argv[i+1]), sizeof(demodir));
+	}
+
+	if (home != NULL) {
+		Q_snprintfz(homepath, sizeof(homepath), "%s/.demonquake/%s",
+		    home, strrchr(com_gamedir, '/') + 1 ?
+		    strrchr(com_gamedir, '/') + 1 : "demonquake");
+		COM_CreatePath(homepath);
+		Sys_mkdir(homepath);
+		COM_AddGameDirectory(homepath);
 	}
 
 	if (!strncmp(demodir, "/rogue", 6)) {
