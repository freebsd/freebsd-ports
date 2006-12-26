--- ./source/files.c.orig	Mon Dec 25 17:07:02 2006
+++ ./source/files.c	Mon Dec 25 17:09:49 2006
@@ -413,6 +413,7 @@
 	char *ext;
 
 	switch( file->mode & FS_PATH_MASK ) {
+	/*
 	case FS_PATH_INIT:
 		Com_sprintf( file->fullpath, sizeof( file->fullpath ),
 			"%s/" INITDIRNAME "/%s", fs_basedir->string, file->name );
@@ -421,6 +422,7 @@
 		Com_sprintf( file->fullpath, sizeof( file->fullpath ),
 			"%s/" BASEDIRNAME "/%s", fs_basedir->string, file->name );
 		break;
+	*/
 	default:
 		Com_sprintf( file->fullpath, sizeof( file->fullpath ),
 			"%s/%s", fs_gamedir, file->name );
@@ -1495,7 +1497,7 @@
 #ifdef _WIN32
 		Com_sprintf( path, sizeof( path ), "%s/%s/gamex86.dll", fs_basedir->string, dirlist[i] );
 #else
-		Com_sprintf( path, sizeof( path ), "%s/%s/gamex86.so", fs_basedir->string, dirlist[i] );
+		Com_sprintf( path, sizeof( path ), "%s/%s/game.so", fs_basedir->string, dirlist[i] );
 #endif
 		Com_ReplaceSeparators( path, PATH_SEP_CHAR );
 
@@ -2153,15 +2155,35 @@
 ================
 */
 static void FS_DefaultGamedir( void ) {
+	/*
 	Com_sprintf( fs_gamedir, sizeof( fs_gamedir ), "%s/"BASEDIRNAME, fs_basedir->string );
 
 	Cvar_Set( "game", "" );
 	Cvar_Set( "gamedir", "" );
+	*/
 }
 
 
 /*
 ================
+FS_AddHomeAsGameDirectory
+
+Adds ~/.q2pro/<dir> as a game directory.
+================
+*/
+void FS_AddHomeAsGameDirectory(char *dir)
+{
+	char	gdir[MAX_OSPATH];	/* Game directory. */
+	char	*homedir;		/* Home directory. */
+
+	if ((homedir = getenv("HOME")) != NULL) {
+		Com_sprintf(gdir, sizeof(gdir), "%s/.q2pro/%s", homedir, dir);
+		FS_AddGameDirectory(gdir);
+	}
+}
+
+/*
+================
 FS_SetupGamedir
 
 Sets the gamedir and path to a different directory.
@@ -2196,7 +2218,10 @@
 	if( fs_cddir->string[0] )
 		FS_AddGameDirectory( va( "%s/%s", fs_cddir->string, fs_game->string ) );
 
+	FS_AddGameDirectory(va("%s/%s", DATADIR, fs_game->string));
+	FS_AddGameDirectory(va("%s/%s", LIBDIR, fs_game->string));
 	FS_AddGameDirectory( va( "%s/%s", fs_basedir->string, fs_game->string ) );
+	FS_AddHomeAsGameDirectory(fs_game->string);
 
 }
 
@@ -2339,7 +2364,10 @@
 	//
 	// start up with baseq2pro by default
 	//
+	FS_AddGameDirectory(va("%s/"INITDIRNAME, DATADIR));
+	FS_AddGameDirectory(va("%s/"INITDIRNAME, LIBDIR));
 	FS_AddGameDirectory( va( "%s/"INITDIRNAME, fs_basedir->string ) );
+	FS_AddHomeAsGameDirectory(INITDIRNAME);
 
 
 	fs_init_searchpaths = fs_searchpaths;
@@ -2363,7 +2391,10 @@
 	//
 	// start up with baseq2 by default
 	//
+	FS_AddGameDirectory(va("%s/"BASEDIRNAME, DATADIR));
+	FS_AddGameDirectory(va("%s/"BASEDIRNAME, LIBDIR));
 	FS_AddGameDirectory( va( "%s/"BASEDIRNAME, fs_basedir->string ) );
+	FS_AddHomeAsGameDirectory(BASEDIRNAME);
 
 	fs_base_searchpaths = fs_searchpaths;
 
