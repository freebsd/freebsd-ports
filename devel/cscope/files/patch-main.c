--- src/main.c.orig	2006-09-30 03:13:00.000000000 -0500
+++ src/main.c	2008-01-18 15:01:59.000000000 -0600
@@ -379,6 +384,7 @@
     }
     /* cleanup on the hangup signal */
     signal(SIGHUP, myexit);
+    signal(SIGTERM, myexit);
 
     /* if the database path is relative and it can't be created */
     if (reffile[0] != '/' && access(".", WRITE) != 0) {
