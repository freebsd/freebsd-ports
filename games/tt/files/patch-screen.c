--- screen.c.orig	2009-06-18 23:13:47.000000000 +0800
+++ screen.c	2011-09-01 09:35:38.000000000 +0800
@@ -190,9 +190,9 @@
   mvaddch (GAME_DEPTH, 2*GAME_WIDTH+2, CORNER_CHAR);
   addch (CORNER_CHAR);
   
-  /* XXX -- Harv's SYSV port uses standout()/standend() here */
-  mvaddstr (0, 2*GAME_WIDTH+6, form ("%sTETRIS FOR TERMINALS%*s%s",
-				     so_str, so_gunk, "", se_str));
+  standout();
+  mvaddstr (0, 2*GAME_WIDTH+6, "TETRIS FOR TERMINALS");
+  standend();
   mvaddstr (2, 2*GAME_WIDTH+6, "Written by Mike Taylor");
   mvaddstr (3, 2*GAME_WIDTH+6, "Email: mirk@uk.co.ssl");
   mvaddstr (4, 2*GAME_WIDTH+6, "Started: Fri May 26 12:26:05 BST 1989");
