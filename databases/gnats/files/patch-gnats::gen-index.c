--- gnats/gen-index.c.orig	Wed Sep 22 08:18:39 1999
+++ gnats/gen-index.c	Sat Jun 14 13:19:58 2003
@@ -256,7 +256,7 @@
   Categories *c;
 
   if (! catfile)
-    sprintf (path, "%s/gnats-adm/%s", gnats_root, CATEGORIES);
+    snprintf (path, PATH_MAX-1, "%s/gnats-adm/%s", gnats_root, CATEGORIES);
   else
     path = catfile;
 
