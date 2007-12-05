--- ../cl/cl_screen.c.orig	2001-06-25 11:19:06.000000000 -0400
+++ ../cl/cl_screen.c	2007-11-15 14:19:50.000000000 -0500
@@ -56,7 +56,7 @@
 	if (F_ISSET(gp, G_SRESTART)) {
 		if (CLSP(sp)) {
 		    delwin(CLSP(sp));
-		    CLSP(sp) = NULL;
+		    LCLSP(sp) = NULL;
 		}
 		if (cl_quit(gp))
 			return (1);
