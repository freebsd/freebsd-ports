--- gnats/index.c.orig	Thu Mar 18 08:45:38 1999
+++ gnats/index.c	Sat Jun 14 13:22:21 2003
@@ -399,7 +399,7 @@
   if (! index_filename)
     {
       index_filename = (char *) xmalloc (PATH_MAX);
-      sprintf (index_filename, "%s/gnats-adm/%s", gnats_root, INDEX);
+      snprintf (index_filename, PATH_MAX-1, "%s/gnats-adm/%s", gnats_root, INDEX);
     }
 
   fp = fopen (index_filename, "r");
