--- gnats/internal.c.orig	Wed Mar  3 09:18:53 1999
+++ gnats/internal.c	Sat Jun 14 14:09:45 2003
@@ -238,7 +238,7 @@
   struct stat buf;
   int count;
 
-  sprintf (path, "%s/gnats-adm/gnats.lock", gnats_root);
+  snprintf (path, PATH_MAX-1, "%s/gnats-adm/gnats.lock", gnats_root);
 
 #define MAXWAIT 10
 #define GRANULARITY 1
