--- src/linux/sys_linux.c.orig	Sun Feb  1 19:06:29 2004
+++ src/linux/sys_linux.c	Sun Feb  1 19:18:07 2004
@@ -217,14 +217,16 @@
 	char	*str_p;
 #if defined __i386__
 	const char *gamename = "gamei386.so";
-#elif defined __x86_64__
-	const char *gamename = "gamex86_64.so";
+#elif defined __amd64__
+	const char *gamename = "gameamd64.so";
 #elif defined __alpha__
-	const char *gamename = "gameaxp.so";
+	const char *gamename = "gamealpha.so";
 #elif defined __powerpc__
 	const char *gamename = "gameppc.so";
 #elif defined __sparc__
 	const char *gamename = "gamesparc.so";
+#elif defined __ia64__
+	const char *gamename = "gameia64.so";
 #else
 #error Unknown arch
 #endif
