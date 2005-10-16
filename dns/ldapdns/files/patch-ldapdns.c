--- ldapdns.c.orig	Mon Jun 23 15:56:44 2003
+++ ldapdns.c	Sun Oct  2 15:13:11 2005
@@ -21,6 +21,7 @@
 		list_push(&x, lp->str);
 		list_push(&seen, lp->str);
 HIT:
+		continue;
 	}
 
 	lp = *p;
