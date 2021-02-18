--- moveall.c.orig	2021-02-18 16:19:37 UTC
+++ moveall.c
@@ -9,8 +9,8 @@ extern int numbadguy;
 
 /* These are the graphics cursors used for drawing the player at */
 /* various times. */
-GC standgc,angelgc,angelugc,angellgc,flygc,hang1gc,hang2gc,up1gc,up2gc;
-GC left1gc,left2gc,right1gc,right2gc;
+extern GC standgc,angelgc,angelugc,angellgc,flygc,hang1gc,hang2gc,up1gc,up2gc;
+extern GC left1gc,left2gc,right1gc,right2gc;
 
 /* Redraw the player.  The graphics cursors all use the GXor function */
 /* so they will not erase what is underneath. */
