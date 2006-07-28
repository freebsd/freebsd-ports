--- files.c.orig	Thu May 19 17:56:13 2005
+++ files.c	Thu Jul 27 17:26:46 2006
@@ -233,7 +233,7 @@
 #ifdef MAGIC_BTREE
 	rb = rbinit (_compare, 1);
 #else
-#ifdef LINUX
+#if defined(__linux__) || defined(__FreeBSD__)
 	rb = rbinit ((int (*)(const void *, const void *))strcmp, 0);
 #else
 	rb = rbinit ((int (*)(const void *, const void *))Q_stricmp, 0);
@@ -1157,6 +1157,8 @@
 	{
 		Com_sprintf (fs_gamedir, sizeof(fs_gamedir), "%s/%s", fs_basedir->string, dir);
 		Cvar_FullSet ("gamedir", dir, CVAR_SERVERINFO|CVAR_NOSET);
+		FS_AddGameDirectory (va("%s/%s", DATADIR, dir));
+		FS_AddGameDirectory (va("%s/%s", LIBDIR, dir));
 		FS_AddGameDirectory (va("%s/%s", fs_basedir->string, dir) );
 	}
 }
@@ -1383,6 +1385,9 @@
 */
 void FS_InitFilesystem (void)
 {
+	char	*home;
+	char	homedir[MAX_OSPATH];
+
 	current_filename = "unknown";
 
 	Cmd_AddCommand ("path", FS_Path_f);
@@ -1412,6 +1417,8 @@
 	//
 	// start up with baseq2 by default
 	//
+	FS_AddGameDirectory (va("%s/"BASEDIRNAME, DATADIR));
+	FS_AddGameDirectory (va("%s/"BASEDIRNAME, LIBDIR));
 	FS_AddGameDirectory (va("%s/"BASEDIRNAME, fs_basedir->string) );
 
 	// any set gamedirs will be freed up to here
@@ -1421,4 +1428,13 @@
 	fs_gamedirvar = Cvar_Get ("game", "", CVAR_LATCH|CVAR_SERVERINFO);
 	if (fs_gamedirvar->string[0])
 		FS_SetGamedir (fs_gamedirvar->string);
+
+	if ((home = getenv("HOME")) != NULL) {
+		strncpy(homedir, home, sizeof(homedir)-1);
+		strncat(homedir, "/.sdlquake2/", sizeof(homedir)-strlen(homedir)-1);
+		Sys_Mkdir(homedir);
+		strncat(homedir, fs_gamedirvar->string[0] ? fs_gamedirvar->string : BASEDIRNAME, sizeof(homedir)-strlen(homedir)-1);
+		Sys_Mkdir(homedir);
+		FS_AddGameDirectory(homedir);
+	}
 }
