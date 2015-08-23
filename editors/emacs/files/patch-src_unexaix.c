--- src/unexaix.c.orig	2015-08-22 16:04:45 UTC
+++ src/unexaix.c
@@ -478,7 +478,7 @@ mark_x (const char *name)
   int um;
   int new = 0;  /* for PERROR */
 
-  um = umask (777);
+  um = umask (0777);
   umask (um);
   if (stat (name, &sbuf) == -1)
     {
