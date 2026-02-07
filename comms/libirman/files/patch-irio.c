--- irio.c.orig	2018-08-12 05:33:43 UTC
+++ irio.c
@@ -97,14 +97,6 @@ int ir_open_port(char *filename)
     return -1;
   }
 
-  /* lock the file for ourselves */
-  if (flock(portfd, LOCK_EX | LOCK_NB) < 0) {
-    /* unable to get lock */
-    close(portfd);
-    portfd = 0;
-    return -1;
-  }
-
   /* get port attributes, store in oldterm */
   if (tcgetattr(portfd, &oldterm) < 0) {
     close(portfd);
