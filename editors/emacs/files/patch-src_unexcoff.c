--- src/unexcoff.c.orig	2015-08-22 16:05:00 UTC
+++ src/unexcoff.c
@@ -451,7 +451,7 @@ mark_x (const char *name)
   int um;
   int new = 0;  /* for PERROR */
 
-  um = umask (777);
+  um = umask (0777);
   umask (um);
   if (stat (name, &sbuf) == -1)
     {
