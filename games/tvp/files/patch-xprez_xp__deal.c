
$FreeBSD$

--- xprez/xp_deal.c.orig	Sun Feb  1 22:32:15 2004
+++ xprez/xp_deal.c	Sun Feb  1 22:16:17 2004
@@ -41,7 +41,7 @@
  */
 int
 xp_deal (ClientData clientdata, Tcl_Interp * interp, int argc, char ** argv) {
-	char ret[200];
+	static char ret[200];
 	int i;
 	hand_t ss;
 
