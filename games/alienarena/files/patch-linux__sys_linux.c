--- ./linux/sys_linux.c.orig	Tue May 16 15:20:10 2006
+++ ./linux/sys_linux.c	Tue May 16 15:20:10 2006
@@ -217,19 +217,7 @@
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
