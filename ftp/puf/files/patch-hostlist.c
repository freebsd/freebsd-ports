--- src/hostlist.c.orig	Sat Jun 12 23:29:16 2004
+++ src/hostlist.c	Sat Jun 12 23:29:42 2004
@@ -267,7 +267,7 @@
 	    else		/*  missed alias  */
 		return 1;
 	}
-noadd:
+noadd:;
     }
 
     if (hapi) {
