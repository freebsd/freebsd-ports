--- unix/sys_unix.c.orig	Wed Jan 11 10:06:28 2006
+++ unix/sys_unix.c	Sat Dec 30 02:03:37 2006
@@ -36,10 +36,6 @@
 #include <sys/mman.h>
 #include <errno.h>
 
-#ifdef __linux__
-#include <mntent.h>
-#endif
-
 #include <dlfcn.h>
 
 #include "../qcommon/qcommon.h"
@@ -220,15 +216,8 @@
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
@@ -236,8 +225,6 @@
 	if (game_library)
 		Com_Error (ERR_FATAL, "Sys_GetGameAPI without Sys_UnloadingGame");
 
-	getcwd(curpath, sizeof(curpath));
-
 	Com_Printf("------- Loading %s -------\n", gamename);
 
 	// now run through the search paths
@@ -247,7 +234,7 @@
 		path = FS_NextPath (path);
 		if (!path)
 			return NULL;		// couldn't find one anywhere
-		sprintf (name, "%s/%s/%s", curpath, path, gamename);
+		sprintf (name, "%s/%s", path, gamename);
 		game_library = dlopen (name, RTLD_LAZY );
 		if (game_library)
 		{
