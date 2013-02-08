--- nubot.c.orig
+++ nubot.c
@@ -1,4 +1,6 @@
 #include <stdio.h>
+#include <stdlib.h>
+#include <strings.h>
 #include <X11/Xlib.h>
 #include "struct.h"
 
@@ -172,7 +174,7 @@
 
     list_moves(player, board, movel);
 
-    if (movel[0].ox==(-1)) return; /* there are no legal moves */
+    if (movel[0].ox==(-1)) return(0); /* there are no legal moves */
 
     if (botlevel==0) {
 	for (ix=0; movel[ix].ox!=(-1); ix++);
@@ -180,7 +182,7 @@
 	best = &(movel[ix]);
 	
 	move_piece(best->ox,best->oy,best->nx,best->ny,player);
-	return;
+	return(0);
     };
     
     for (ix=0; movel[ix].ox!=(-1); ix++) {
