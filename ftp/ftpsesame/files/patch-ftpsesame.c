--- ftpsesame.c.orig	Mon May  1 01:30:43 2006
+++ ftpsesame.c	Mon May  1 01:30:51 2006
@@ -663,7 +663,7 @@
 	gotsig_close = 1;
 }
 
-__dead void
+void
 usage(void)
 {
 	fprintf(stderr, "usage: %s [-d] [-D level] [-i interface] " \
