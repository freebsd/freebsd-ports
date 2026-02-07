--- src/linux/sys_linux.c.orig	Sun Sep 12 15:26:29 2004
+++ src/linux/sys_linux.c	Fri Oct  7 17:32:46 2005
@@ -215,19 +215,7 @@
 	char	name[MAX_OSPATH];
 	char	*path;
 	char	*str_p;
-#if defined __i386__
-	const char *gamename = "gamei386.so";
-#elif defined __x86_64__
-	const char *gamename = "gamex86_64.so";
-#elif defined __alpha__
-	const char *gamename = "gameaxp.so";
-#elif defined __powerpc__
-	const char *gamename = "gameppc.so";
-#elif defined __sparc__
-	const char *gamename = "gamesparc.so";
-#else
-#error Unknown arch
-#endif
+	const char *gamename = "game.so";
 
 	setreuid(getuid(), getuid());
 	setegid(getgid());
