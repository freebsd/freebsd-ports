--- ftpsesame.c.orig	2004-10-05 12:07:24 UTC
+++ ftpsesame.c
@@ -663,7 +663,7 @@ sig_close(int sig)
 	gotsig_close = 1;
 }
 
-__dead void
+void
 usage(void)
 {
 	fprintf(stderr, "usage: %s [-d] [-D level] [-i interface] " \
