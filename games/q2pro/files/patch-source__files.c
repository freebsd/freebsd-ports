--- source/files.c.orig	Tue Jan 30 18:07:53 2007
+++ source/files.c	Sun Feb  4 19:31:21 2007
@@ -1542,6 +1542,22 @@
 
 }
 
+#ifdef __unix__
+/*
+================
+FS_AddHomeAsGameDirectory
+
+Adds ~/.q2pro/<dir> as a game directory.
+================
+*/
+void FS_AddHomeAsGameDirectory(char *dir)
+{
+	char	*homedir;		/* Home directory. */
+
+	if ((homedir = getenv("HOME")) != NULL)
+		FS_AddGameDirectory("%s/"HOMEDIRNAME"/%s", homedir, dir);
+}
+#endif
 
 /*
 =================
@@ -1569,7 +1585,7 @@
 #ifdef _WIN32
 		Com_sprintf( path, sizeof( path ), "%s/%s/gamex86.dll", fs_basedir->string, dirlist[i] );
 #else
-		Com_sprintf( path, sizeof( path ), "%s/%s/gamei386.so", fs_basedir->string, dirlist[i] );
+		Com_sprintf( path, sizeof( path ), "%s/%s/game.so", fs_basedir->string, dirlist[i] );
 #endif
 
 		if( !( fp = fopen( path, "rb" ) ) ) {
@@ -2358,21 +2374,15 @@
 */
 static void FS_DefaultGamedir( void ) {
 #ifdef __unix__
-    char *homedir = getenv( "HOME" );
-
-    if( homedir ) {
-    	FS_AddGameDirectory( "%s/"HOMEDIRNAME"/"BASEDIRNAME, homedir );
-    } else
+	FS_AddHomeAsGameDirectory(BASEDIRNAME);
 #else
-    {
 		/* write to baseq2pro on Windows */
     	Com_sprintf( fs_gamedir, sizeof( fs_gamedir ), "%s/"INITDIRNAME,
             fs_basedir->string );
-    }
-#endif
 
 	Cvar_Set( "game", "" );
 	Cvar_Set( "gamedir", "" );
+#endif
 }
 
 
@@ -2410,18 +2420,11 @@
 	if( fs_cddir->string[0] )
 		FS_AddGameDirectory( "%s/%s", fs_cddir->string, fs_game->string );
 
+	FS_AddGameDirectory("%s/%s", DATADIR, fs_game->string);
+	FS_AddGameDirectory("%s/%s", LIBDIR, fs_game->string);
 	FS_AddGameDirectory( "%s/%s", fs_basedir->string, fs_game->string );
+	FS_AddHomeAsGameDirectory(fs_game->string);
 
-#ifdef __unix__
-    {
-        char *homedir = getenv( "HOME" );
-
-        if( homedir ) {
-            FS_AddGameDirectory( "%s/"HOMEDIRNAME"/%s",
-                homedir, fs_game->string );
-        }
-    }
-#endif
 }
 
 qboolean FS_SafeToRestart( void ) {
@@ -2518,7 +2521,6 @@
 */
 void FS_Init( void ) {
 	int	startTime, i;
-    char *base;
 
 	startTime = Sys_Milliseconds();
 
@@ -2554,13 +2556,7 @@
 	// allows the game to run from outside the data tree
 	//
 
-#ifdef __unix__
-    base = DATADIR;
-#else
-    base = Sys_GetCurrentDirectory();
-#endif
-
-	fs_basedir = Cvar_Get( "basedir", base, CVAR_NOSET );
+	fs_basedir = Cvar_Get( "basedir", Sys_GetCurrentDirectory(), CVAR_NOSET );
 	
 	/* strip trailing slash */
 	if( fs_basedir->string[0] ) {
@@ -2591,8 +2587,15 @@
 	//
 	// start up with baseq2 by default
 	//
+	FS_AddGameDirectory("%s/"BASEDIRNAME, DATADIR);
+	FS_AddGameDirectory("%s/"BASEDIRNAME, LIBDIR);
 	FS_AddGameDirectory( "%s/"BASEDIRNAME, fs_basedir->string );
+	FS_AddHomeAsGameDirectory(BASEDIRNAME);
+
+	FS_AddGameDirectory("%s/"INITDIRNAME, DATADIR);
+	FS_AddGameDirectory("%s/"INITDIRNAME, LIBDIR);
 	FS_AddGameDirectory( "%s/"INITDIRNAME, fs_basedir->string );
+	FS_AddHomeAsGameDirectory(INITDIRNAME);
 
 	fs_base_searchpaths = fs_searchpaths;
 
