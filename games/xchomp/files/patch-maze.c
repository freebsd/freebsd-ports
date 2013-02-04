--- maze.c.orig
+++ maze.c
@@ -124,7 +124,7 @@
 		  "z---x---x---x---x---c" } };
 
 
-read_maze(num)
+void read_maze(num)
 int num;
 {
    int          i, xx, yy;
@@ -259,7 +259,7 @@
  * The function which follows is used at the beginning of each level to
  * set up the initial parameters for all of the moving figures.
  */
-position_players()
+void position_players()
 {
    int 		i;
    XRectangle	ghost_rect[MAX_GHOSTS], pac_rect;
