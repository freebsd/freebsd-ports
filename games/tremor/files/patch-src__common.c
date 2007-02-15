--- common.c.orig	Fri Jan 12 10:37:34 2007
+++ common.c	Thu Feb 15 00:51:54 2007
@@ -1599,9 +1599,13 @@
 {
 	searchpath_t    *search,*otherpaths=NULL;
 	pack_t          *pak;
-	char      	*filename;        
+	char      	*filename, *p;
 	dirdata_t 	dirdata;
 
+	if ((p = strrchr(dir, '/')))
+		Q_strncpyz (com_gamedirname, ++p, sizeof(com_gamedirname));
+	else
+		Q_strncpyz (com_gamedirname, p, sizeof(com_gamedirname));
 // update current gamedir
 	Q_strncpyz (com_gamedir, dir, sizeof(com_gamedir));
 //
@@ -1768,7 +1772,7 @@
 {
 	int	i;
 #if defined (HOMEDIR)
-	char	*home, *tmp;
+	char	*home, homepath[MAX_OSPATH];
 	home = getenv("HOME");
 #endif
 
@@ -1797,7 +1801,11 @@
 	if (home != NULL)
 		COM_AddGameDirectory(va("%s/"HOMEDIR"/"GAMENAME, home));
 #endif
-	COM_AddGameDirectory (va("%s/base", com_basedir));	// JT021305 - use base as default GAMENAME
+	COM_AddGameDirectory (va("%s/tremor", com_basedir));
+#if defined (HOMEDIR)
+	if (home != NULL)
+		COM_AddGameDirectory(va("%s/"HOMEDIR"/tremor", home));
+#endif
 
 	if (COM_CheckParm("-rogue"))
 		COM_AddGameDirectory (va("%s/rogue", com_basedir));
@@ -1818,15 +1826,12 @@
         	COM_AddGameDirectory (va("%s/%s", com_basedir, com_argv[i+1]));
 
 #if defined (HOMEDIR)
-	tmp = Sys_HomeDir();
-	Sys_mkdir(tmp);
-	COM_AddGameDirectory (tmp);
-	chdir(tmp);
-	if ((i = COM_CheckParm("-game")) && i < com_argc-1)
-	{
-		tmp = va("%s/%s", Sys_HomeDir(), com_argv[i+1]);
-		Sys_mkdir(tmp);
-		COM_AddGameDirectory (tmp);
+	if (home != NULL) {
+		Q_snprintfz(homepath, sizeof(homepath), "%s/"HOMEDIR"/%s",
+		    home, com_gamedirname);
+		COM_CreatePath(homepath);
+		Sys_mkdir(homepath);
+		COM_AddGameDirectory(homepath);
 	}
 #endif
 }
