--- greed.c.orig	Sun Apr 15 00:13:39 2001
+++ greed.c	Sun Apr 15 00:13:56 2001
@@ -200,7 +200,6 @@
 char *argv[];
 {
 	register val = 1;
-	extern long time();
 	int attribs[9];
 #ifdef A_COLOR
 	char *colors;
