--- code/qcommon/files.c.orig	2009-12-08 11:07:08.000000000 +0100
+++ code/qcommon/files.c	2009-12-08 11:08:41.000000000 +0100
@@ -241,6 +241,7 @@
 #endif
 
 static	cvar_t		*fs_basepath;
+static	cvar_t		*fs_libpath;
 static	cvar_t		*fs_basegame;
 static	cvar_t		*fs_gamedirvar;
 static	searchpath_t	*fs_searchpaths;
@@ -2761,6 +2762,7 @@
 	fs_debug = Cvar_Get( "fs_debug", "0", 0 );
 	fs_basepath = Cvar_Get ("fs_basepath", Sys_DefaultInstallPath(), CVAR_INIT );
 	fs_basegame = Cvar_Get ("fs_basegame", "", CVAR_INIT );
+	fs_libpath = Cvar_Get ("fs_libpath", Sys_DefaultLibPath(), CVAR_INIT );
 	homePath = Sys_DefaultHomePath();
 	if (!homePath || !homePath[0]) {
 		homePath = fs_basepath->string;
