--- src/game.c.orig	2015-04-07 14:37:56 UTC
+++ src/game.c
@@ -31,11 +31,7 @@
 
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
 
