
$FreeBSD$

--- src/complete.c.orig	Mon Aug 23 17:17:13 2004
+++ src/complete.c	Mon Aug 23 17:17:24 2004
@@ -183,6 +183,7 @@
 				sizeof(u_char *));
 		}
 next:
+	;
 	}
 	comps[i] = NULL;
 
