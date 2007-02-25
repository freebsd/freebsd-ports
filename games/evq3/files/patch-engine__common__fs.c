--- engine/common/fs.c.orig	Wed Dec 20 20:29:46 2006
+++ engine/common/fs.c	Sat Dec 23 13:16:38 2006
@@ -3115,6 +3115,7 @@
 	fs_debug = Cvar_Get("fs_debug", "0", 0);
 	fs_copyfiles = Cvar_Get("fs_copyfiles", "0", CVAR_INIT);
 	fs_cdpath = Cvar_Get("fs_cdpath", Sys_DefaultCDPath(), CVAR_INIT);
+	Sys_SetDefaultInstallPath("%%DATADIR%%");
 	fs_basepath = Cvar_Get("fs_basepath", Sys_DefaultInstallPath(), CVAR_INIT);
 	fs_basegame = Cvar_Get("fs_basegame", "", CVAR_INIT);
 	homePath = Sys_DefaultHomePath();
@@ -3135,6 +3136,7 @@
 	{
 		FS_AddGameDirectory(fs_basepath->string, gameName);
 	}
+	FS_AddGameDirectory( "%%LIBDIR%%", gameName );
 	// fs_homepath is somewhat particular to *nix systems, only add if relevant
 	// NOTE: same filtering below for mods and basegame
 	if(fs_basepath->string[0] && Q_stricmp(fs_homepath->string, fs_basepath->string))
@@ -3153,6 +3155,7 @@
 		{
 			FS_AddGameDirectory(fs_basepath->string, fs_basegame->string);
 		}
+		FS_AddGameDirectory("%%LIBDIR%%", fs_basegame->string);
 		if(fs_homepath->string[0] && Q_stricmp(fs_homepath->string, fs_basepath->string))
 		{
 			FS_AddGameDirectory(fs_homepath->string, fs_basegame->string);
@@ -3170,6 +3173,7 @@
 		{
 			FS_AddGameDirectory(fs_basepath->string, fs_gamedirvar->string);
 		}
+		FS_AddGameDirectory("%%LIBDIR%%", fs_gamedirvar->string);
 		if(fs_homepath->string[0] && Q_stricmp(fs_homepath->string, fs_basepath->string))
 		{
 			FS_AddGameDirectory(fs_homepath->string, fs_gamedirvar->string);
