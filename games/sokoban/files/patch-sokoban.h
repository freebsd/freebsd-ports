--- ./sokoban.h.orig	1992-05-15 01:15:26.000000000 -0400
+++ ./sokoban.h	2014-03-11 22:16:45.005739636 -0400
@@ -1,6 +1,14 @@
 /***********************************************************************
    You may wish to alter the following directory paths
 ***********************************************************************/
+
+#ifdef PREFIX
+#define SCREENPATH	PREFIX	"/share/sokoban/screens"
+#define SAVEPATH	PREFIX	"/share/sokoban"
+#define LOCKFILE		"/tmp/sok.tmp"
+#define SCOREFILE		"/var/games/sokoban"
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
