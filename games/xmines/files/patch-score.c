--- score.c.orig	Fri Dec  3 23:18:35 1993
+++ score.c	Sat Aug  5 07:48:43 2000
@@ -6,7 +6,9 @@
 
 
 FILE *scoreFile;
+#ifndef SCOREfILE
 #define SCOREfILE "/usr/X386/lib/X11/games/xbomb-scores"
+#endif
 #define NUMsCORES 10
 #define NAMEsIZE 50
 #define SCOREfORMAT "%5d %s\n"
