--- game.c.orig	2001-01-01 18:42:51 UTC
+++ game.c
@@ -28,7 +28,7 @@
 
 // Radar
 
-radarStruct radar;
+extern radarStruct radar;
 
 // Pixmaps
 Pixmap *tile;
@@ -59,7 +59,6 @@ extern bool ENDMAP;
 extern int mapResult;
 extern bool crashed;
 extern aiStruct AI;
-extern FILE *log;
 extern char livesString[10];
 extern char mapString[15];
 extern char *hiString;
