--- ./unix/sys_unix.c.orig	Wed Jan  4 07:57:40 2006
+++ ./unix/sys_unix.c	Fri Jul 28 13:30:29 2006
@@ -220,15 +220,8 @@
 	void	*(*GetGameAPI) (void *);
 
 	char	name[MAX_OSPATH];
-	char	curpath[MAX_OSPATH];
 	char	*path;
-#ifdef __i386__
-	const char *gamename = "gamei386.so";
-#elif defined __alpha__
-	const char *gamename = "gameaxp.so";
-#else
-#error Unknown arch
-#endif
+	const char *gamename = "game.so";
 
 	setreuid(getuid(), getuid());
 	setegid(getgid());
@@ -236,8 +229,6 @@
 	if (game_library)
 		Com_Error (ERR_FATAL, "Sys_GetGameAPI without Sys_UnloadingGame");
 
-	getcwd(curpath, sizeof(curpath));
-
 	Com_Printf("------- Loading %s -------\n", gamename);
 
 	// now run through the search paths
@@ -247,7 +238,7 @@
 		path = FS_NextPath (path);
 		if (!path)
 			return NULL;		// couldn't find one anywhere
-		sprintf (name, "%s/%s/%s", curpath, path, gamename);
+		sprintf (name, "%s/%s", path, gamename);
 		game_library = dlopen (name, RTLD_LAZY );
 		if (game_library)
 		{
@@ -319,6 +310,7 @@
 
 void Sys_CopyProtect(void)
 {
+#if 0
 	FILE *mnt;
 	struct mntent *ent;
 	char path[MAX_OSPATH];
@@ -366,6 +358,7 @@
 		Com_Error (ERR_FATAL, "Could not find a Quake2 CD in your CD drive.");
 	Com_Error (ERR_FATAL, "Unable to find a mounted iso9660 file system.\n"
 		"You must mount the Quake2 CD in a cdrom drive in order to play.");
+#endif
 }
 
 #if 0
