--- ./client/sys_linux.c.orig	2008-02-15 11:45:36.000000000 -0300
+++ ./client/sys_linux.c	2008-02-15 11:45:37.000000000 -0300
@@ -371,7 +371,7 @@
 	char name[MAX_OSPATH];
 	char curpath[MAX_OSPATH];
 	char *searchpath;
-	const char *gamename = "gamei386.so";
+	const char *gamename = "game.so";
 
 	void *ret;
 
