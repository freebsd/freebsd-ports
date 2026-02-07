--- ldapdns.c.orig	2014-05-03 14:11:48.555553477 -0700
+++ ldapdns.c	2014-05-03 14:13:35.212669115 -0700
@@ -21,6 +21,7 @@
 		list_push(&x, lp->str);
 		list_push(&seen, lp->str); HIT:
+		continue;
 	}
 
 	lp = *p;
