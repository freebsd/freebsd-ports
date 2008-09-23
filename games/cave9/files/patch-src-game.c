--- src/game.c.orig	2008-09-15 23:11:44.000000000 +0400
+++ src/game.c	2008-09-23 23:06:05.000000000 +0400
@@ -29,11 +29,7 @@
 
 const char* data_paths[] =
 {
-	"data",
-	"./data",
-	"~/.cave9/data",
-	"/usr/local/share/cave9",
-	"/usr/share/cave9",
+	DATADIR,
 	NULL
 };
 
