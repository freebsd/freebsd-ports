--- ./server/sv_sys_unix.c.orig	Tue Jul 18 00:34:46 2006
+++ ./server/sv_sys_unix.c	Sat Sep  2 18:41:11 2006
@@ -807,18 +807,15 @@
 	void *(*GetGameAPI)(void *);
 
 	char name[MAX_OSPATH];
-	char curpath[MAX_OSPATH];
 	char *searchpath;
-	const char *gamename = "gamei386.so";
+	const char *gamename = "game.so";
 
 	void *ret;
 
-	getcwd(curpath, sizeof(curpath));
-
 	searchpath = 0;
 	while((searchpath = COM_NextPath(searchpath)))
 	{
-		sprintf (name, "%s/%s/%s", curpath, searchpath, gamename);
+		sprintf (name, "%s/%s", searchpath, gamename);
 		game_library = dlopen (name, RTLD_LAZY );
 		if (game_library)
 		{
