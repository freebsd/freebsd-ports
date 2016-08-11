--- code/qcommon/files.c.orig	2011-12-24 12:29:32 UTC
+++ code/qcommon/files.c
@@ -250,6 +250,7 @@ static  cvar_t          *fs_apppath;
 #endif
 
 static	cvar_t		*fs_basepath;
+static	cvar_t		*fs_libpath;
 static	cvar_t		*fs_basegame;
 static	cvar_t		*fs_gamedirvar;
 static	searchpath_t	*fs_searchpaths;
@@ -2859,6 +2860,7 @@ static void FS_Startup( const char *game
 	fs_debug = Cvar_Get( "fs_debug", "0", 0 );
 	fs_basepath = Cvar_Get ("fs_basepath", Sys_DefaultInstallPath(), CVAR_INIT );
 	fs_basegame = Cvar_Get ("fs_basegame", "", CVAR_INIT );
+	fs_libpath = Cvar_Get ("fs_libpath", Sys_DefaultLibPath(), CVAR_INIT );
 	homePath = Sys_DefaultHomePath();
 	if (!homePath || !homePath[0]) {
 		homePath = fs_basepath->string;
@@ -2878,6 +2880,11 @@ static void FS_Startup( const char *game
 	if (fs_apppath->string[0])
 		FS_AddGameDirectory(fs_apppath->string, gameName);
 	#endif
+
+	// Search default library location if given
+	if (fs_libpath->string[0]) {
+		FS_AddGameDirectory ( fs_libpath->string, gameName );
+	}
 	
 	// NOTE: same filtering below for mods and basegame
 	if (fs_homepath->string[0] && Q_stricmp(fs_homepath->string,fs_basepath->string)) {
