
$FreeBSD$

--- src/h2_main.c.orig	Tue Dec  4 18:11:47 2001
+++ src/h2_main.c	Mon Feb 10 16:56:31 2003
@@ -127,7 +127,7 @@
 static char *wadfiles[MAXWADFILES] =
 {
 	"hexen.wad",
-	"/usr/local/share/games/uhexen/hexen.wad"
+	PREFIX "/share/uhexen/hexen.wad"
 };
 #else
 static char *wadfiles[MAXWADFILES] =
