--- reload.c.orig	Sat Nov 11 05:23:54 1995
+++ reload.c	Mon Mar 20 13:29:11 2000
@@ -5899,7 +5899,7 @@
 	fprintf (stderr, ", inc by %d\n", reload_inc[r]);
 
       if (reload_nocombine[r])
-	fprintf (stderr, ", can combine", reload_nocombine[r]);
+	fprintf (stderr, ", can combine");
 
       if (reload_secondary_p[r])
 	fprintf (stderr, ", secondary_reload_p");
