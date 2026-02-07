--- source/sys_unix.c.orig	Sun Jan 28 20:57:44 2007
+++ source/sys_unix.c	Sun Feb  4 19:49:07 2007
@@ -908,7 +908,7 @@
 
 static void	*gameLibrary;
 
-#define	GAMELIB		"gamei386.so"
+#define	GAMELIB		"game.so"
 
 /*
 =================
@@ -935,9 +935,9 @@
 	char	name[MAX_OSPATH];
 	char	*path;
 #ifdef NDEBUG
-	const char *debugdir = "releasei386";
+	const char *debugdir = "release";
 #else
-	const char *debugdir = "debugi386";
+	const char *debugdir = "debug";
 #endif
 
 	if( gameLibrary ) {
