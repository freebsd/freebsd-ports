--- hiscore.c.orig	Fri Jan 16 20:50:39 1998
+++ hiscore.c	Fri Feb 20 10:23:20 1998
@@ -47,7 +47,9 @@
            nbombs[NLEVELS];     /*+ number of bombs. +*/
 
 /*+ The names of the high score tables. +*/
-static char *filenames[NTYPES]={"/var/tmp/xbomb6.hi","/var/tmp/xbomb4.hi","/var/tmp/xbomb3.hi"};
+static char *filenames[NTYPES]={"/var/games/xbomb/xbomb6.hi",
+                                "/var/games/xbomb/xbomb4.hi",
+                                "/var/games/xbomb/xbomb3.hi"};
 
 /*+ The names of the positions in the high score tables. +*/
 static char pos[11][5]={"Top","2nd","3rd","4th","5th","6th","7th","8th","9th","10th","Lost"};
