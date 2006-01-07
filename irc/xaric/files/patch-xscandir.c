--- xscandir.c.orig	Sun Jan  8 07:58:21 2006
+++ xscandir.c	Sun Jan  8 08:00:46 2006
@@ -84,7 +84,7 @@
 static int the_longest;
 
 /* used by scandir to select entries */
-static int dselect(const struct dirent *d)
+static int dselect(struct dirent *d)
 {
     int t;
 
