--- drivers.c.orig
+++ drivers.c
@@ -12,7 +12,7 @@
  * variables (pac_x, pac_y), the direction variables (pac_ix, pac_iy),
  * and the clipping region (pac_region).
  */
-control_pac()
+void control_pac()
 {
    register int         xx = pac_x, yy = pac_y, i, dx, dy;
    register char        *pc = md[yy >> 4] + (xx >> 4);
@@ -89,7 +89,7 @@
  * eaten something which is not a ghost -- a dot, a power-dot,
  * or the fruit.  If so, the appropriate action is taken.
  */
-check_dots()
+void check_dots()
 {
    register char        *pi;
    register int         i;
@@ -218,7 +218,7 @@
  * The function below causes ghosts to follow the player around, with a bit
  * of randomness thrown in as well.
  */
-follow(i)
+void follow(i)
 register int i;
 {
    int            xx = ghost_x[i], yy = ghost_y[i];
@@ -289,7 +289,7 @@
  * at half speed.  It is set up as the driver function during
  * the ghost-eating periods of the game.
  */
-run(i)
+void run(i)
 register int i;
 {
    int            xx = ghost_x[i], yy = ghost_y[i];
@@ -358,7 +358,7 @@
  * high speed.  It is set up as the driver for ghosts which have
  * been eaten.
  */
-go_home(i)
+void go_home(i)
 register int i;
 {
    int            xx = ghost_x[i], yy = ghost_y[i];
@@ -459,14 +459,14 @@
  * They simply hover around in a circular pattern.  Randomness is
  * used to decide when the ghosts leave the box.
  */
-hover(i)
+void hover(i)
 register int i;
 {
    register int yy = ghost_y[i] >> 4, xx = ghost_x[i] >> 4;
    char         *pc = md[yy] + xx;
    register int *px = ghost_ix + i, *py = ghost_iy + i;
 
-   if (xx == door_x)
+   if (xx == door_x) {
       if (yy == (door_y - 1)) {
 
 	 /*
@@ -490,6 +490,7 @@
                *px = 0, *py = (-2);
                return;
             }
+   }
 
    /*
     * The rest of the function drives the ghost around the
@@ -514,14 +515,14 @@
  * the ghost-eating periods of the game -- they move at half
  * speed.
  */
-hover2(i)
+void hover2(i)
 register int i;
 {
    register int yy = ghost_y[i] >> 4, xx = ghost_x[i] >> 4;
    char         *pc = md[yy] + xx;
    register int *px = ghost_ix + i, *py = ghost_iy + i;
 
-   if (xx == door_x)
+   if (xx == door_x) {
       if (yy == (door_y - 1)) {
          drive[i] = run;
          run(i);
@@ -532,6 +533,7 @@
             *px = 0, *py = (-1);
             return;
          }
+   }
 
    if (*px > 0) {
       if (pc[1]) *px = 0, *py = (-1);
