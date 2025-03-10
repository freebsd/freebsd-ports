--- sokoban.h.orig	1992-05-15 05:15:26 UTC
+++ sokoban.h
@@ -1,6 +1,14 @@
 /***********************************************************************
    You may wish to alter the following directory paths
 ***********************************************************************/
+
+#ifdef PREFIX
+#define SCREENPATH	PREFIX	"/share/sokoban/screens"
+#define SAVEPATH		"/var/games/sokoban"
+#define LOCKFILE		"/tmp/sok.tmp"
+#define SCOREFILE		"/var/games/sokoban/scores"
+#else
+
 /**/
 /* SCREENPATH: the name of the directioy where the screen file are held */
 /**/
@@ -24,6 +32,8 @@
 /**/
 #define SCOREFILE	"/usr/games/sokob/highscore"
 
+#endif
+
 /**/
 /* MAXUSERNAME: defines the maximum length of a system's user name */
 /**/
@@ -32,7 +42,7 @@
 /**/
 /* MAXSCOREENTRIES: defines the maximum numner of entries in the scoretable */
 /**/
-#define MAXSCOREENTRIES	50
+#define MAXSCOREENTRIES	90

 /**/
 /* SUPERUSER: defines the name of the game superuser */
