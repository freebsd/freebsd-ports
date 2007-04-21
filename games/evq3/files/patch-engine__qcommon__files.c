--- engine/qcommon/files.c.orig	Fri Apr 20 16:29:25 2007
+++ engine/qcommon/files.c	Fri Apr 20 16:50:00 2007
@@ -2798,6 +2798,7 @@
 	fs_debug = Cvar_Get( "fs_debug", "0", 0 );
 	fs_copyfiles = Cvar_Get( "fs_copyfiles", "0", CVAR_INIT );
 	fs_cdpath = Cvar_Get ("fs_cdpath", Sys_DefaultCDPath(), CVAR_INIT );
+	Sys_SetDefaultInstallPath(DATADIR);
 	fs_basepath = Cvar_Get ("fs_basepath", Sys_DefaultInstallPath(), CVAR_INIT );
 	fs_basegame = Cvar_Get ("fs_basegame", "", CVAR_INIT );
   homePath = Sys_DefaultHomePath();
@@ -2815,6 +2816,7 @@
 	if (fs_basepath->string[0]) {
 		FS_AddGameDirectory( fs_basepath->string, gameName );
 	}
+	FS_AddGameDirectory( LIBDIR, gameName );
   // fs_homepath is somewhat particular to *nix systems, only add if relevant
   // NOTE: same filtering below for mods and basegame
 	if (fs_basepath->string[0] && Q_stricmp(fs_homepath->string,fs_basepath->string)) {
@@ -2829,6 +2831,7 @@
 		if (fs_basepath->string[0]) {
 			FS_AddGameDirectory(fs_basepath->string, fs_basegame->string);
 		}
+		FS_AddGameDirectory(LIBDIR, fs_basegame->string);
 		if (fs_homepath->string[0] && Q_stricmp(fs_homepath->string,fs_basepath->string)) {
 			FS_AddGameDirectory(fs_homepath->string, fs_basegame->string);
 		}
@@ -2842,6 +2845,7 @@
 		if (fs_basepath->string[0]) {
 			FS_AddGameDirectory(fs_basepath->string, fs_gamedirvar->string);
 		}
+		FS_AddGameDirectory(LIBDIR, fs_basegame->string);
 		if (fs_homepath->string[0] && Q_stricmp(fs_homepath->string,fs_basepath->string)) {
 			FS_AddGameDirectory(fs_homepath->string, fs_gamedirvar->string);
 		}
