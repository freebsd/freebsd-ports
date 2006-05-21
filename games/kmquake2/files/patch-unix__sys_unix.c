--- ./unix/sys_unix.c.orig	Thu Apr  6 11:30:11 2006
+++ ./unix/sys_unix.c	Sat May 20 13:44:43 2006
@@ -219,23 +219,10 @@
 	void	*(*GetGameAPI) (void *);
 
 	char	name[MAX_OSPATH];
-	char	curpath[MAX_OSPATH];
 	char	*path;
 
 	// Knightmare- changed game library name for better cohabitation
-#ifdef __i386__
-	const char *gamename = "kmq2gamei386.so";
-#elif defined __alpha__
-	const char *gamename = "kmq2gameaxp.so";
-#elif defined __x86_64__
-	const char *gamename = "kmq2gamex86_64.so";
-#elif defined __powerpc__
-	const char *gamename = "kmq2gameppc.so";
-#elif defined __sparc__
-	const char *gamename = "kmq2gamesparc.so";
-#else
-#error Unknown arch
-#endif
+	const char *gamename = "kmq2game.so";
 
 	setreuid(getuid(), getuid());
 	setegid(getgid());
@@ -243,8 +230,6 @@
 	if (game_library)
 		Com_Error (ERR_FATAL, "Sys_GetGameAPI without Sys_UnloadingGame");
 
-	getcwd(curpath, sizeof(curpath));
-
 	Com_Printf("------- Loading %s -------\n", gamename);
 
 	// now run through the search paths
@@ -254,7 +239,7 @@
 		path = FS_NextPath (path);
 		if (!path)
 			return NULL;		// couldn't find one anywhere
-		sprintf (name, "%s/%s/%s", curpath, path, gamename);
+		sprintf (name, "%s/%s", path, gamename);
 		game_library = dlopen (name, RTLD_LAZY );
 		if (game_library)
 		{
