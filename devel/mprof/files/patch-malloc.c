--- malloc.c.orig	Wed Apr 21 04:36:17 1993
+++ malloc.c	Tue Jun 19 02:43:44 2007
@@ -261,6 +261,8 @@
  */
 int realloc_srchlen = 4;	/* 4 should be plenty, -1 =>'s whole list */
 
+static findbucket(union overhead *, int srchlen);
+
 char *
 realloc(cp, nbytes)
 	char *cp; 
