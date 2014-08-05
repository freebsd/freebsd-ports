--- ./server/save.c.orig	2014-08-05 15:15:31.916658572 +0200
+++ ./server/save.c	2014-08-05 15:15:32.016684533 +0200
@@ -941,7 +941,7 @@
 #ifdef VERIFY_SAVEFILE
 
 		/* Lock on savefile */
-		strcpy(temp, savefile);
+		strcpy(temp, p_ptr->savefile);
 		strcat(temp, ".lok");
 
 		/* Remove lock file */
