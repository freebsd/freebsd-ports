$FreeBSD$

--- common/main.c.orig	Sun Jan  4 17:35:52 2004
+++ common/main.c	Sun Jan  4 17:36:09 2004
@@ -93,6 +93,7 @@
 	else {
 		/* Nview, view are readonly. */
 		if (!strcmp(gp->progname, "nview") ||
+		    !strcmp(gp->progname, "pnview") ||
 		    !strcmp(gp->progname, "view"))
 			readonly = 1;
 		
