--- src/linux/sys_linux.c.orig	Sun Feb  1 19:06:29 2004
+++ src/linux/sys_linux.c	Sun Feb  1 19:18:07 2004
@@ -223,6 +223,10 @@
 	const char *gamename = "gameppc.so";
 #elif defined __sparc__
 	const char *gamename = "gamesparc.so";
+#elif defined __amd64__
+	const char *gamename = "gameamd64.so";
+#elif defined __ia64__
+	const char *gamename = "gameia64.so";
 #else
 #error Unknown arch
 #endif
