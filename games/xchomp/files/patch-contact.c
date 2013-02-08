--- contact.c.orig
+++ contact.c
@@ -17,7 +17,7 @@
  * with which the player collided.  In this case, it doesn't matter.
  */
 /*ARGSUSED*/
-die(dummy)
+void die(dummy)
 int dummy;
 {
    register int xx = pac_x, yy = pac_y, i, dx, dy;
@@ -116,7 +116,7 @@
  * of the eaten ghost, and then continues.  The parameter is
  * the array index of the eaten ghost.
  */
-eat(i)
+void eat(i)
 int i;
 {
    register int  xx = pac_x, yy = pac_y, j;
@@ -166,7 +166,7 @@
  * The eyes are harmless; this is a no-op.
  */
 /*ARGSUSED*/
-noop(dummy)
+void noop(dummy)
 int dummy;
 {
 }
