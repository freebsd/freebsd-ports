--- unix/sys_unix.c.orig	2006-01-11 13:06:28 UTC
+++ unix/sys_unix.c
@@ -36,10 +36,6 @@ Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 #include <sys/mman.h>
 #include <errno.h>
 
-#ifdef __linux__
-#include <mntent.h>
-#endif
-
 #include <dlfcn.h>
 
 #include "../qcommon/qcommon.h"
@@ -220,15 +216,8 @@ void *Sys_GetGameAPI (void *parms)
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
@@ -236,8 +225,6 @@ void *Sys_GetGameAPI (void *parms)
 	if (game_library)
 		Com_Error (ERR_FATAL, "Sys_GetGameAPI without Sys_UnloadingGame");
 
-	getcwd(curpath, sizeof(curpath));
-
 	Com_Printf("------- Loading %s -------\n", gamename);
 
 	// now run through the search paths
@@ -247,7 +234,7 @@ void *Sys_GetGameAPI (void *parms)
 		path = FS_NextPath (path);
 		if (!path)
 			return NULL;		// couldn't find one anywhere
-		sprintf (name, "%s/%s/%s", curpath, path, gamename);
+		sprintf (name, "%s/%s", path, gamename);
 		game_library = dlopen (name, RTLD_LAZY );
 		if (game_library)
 		{
