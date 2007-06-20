--- animate.c.orig	Thu Mar 28 15:16:53 1996
+++ animate.c	Fri Jun 15 02:11:35 2007
@@ -9,6 +9,10 @@
 
 extern int	iscolor;
 
+static do_animate();
+static draw_square();
+static compute_position();
+
 animate_move (player, orig_type, orig_arg, dest_type, dest_arg)
 {
 #if 1
