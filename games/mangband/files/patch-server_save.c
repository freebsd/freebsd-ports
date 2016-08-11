--- server/save.c.orig	2016-05-31 18:05:21 UTC
+++ server/save.c
@@ -941,7 +941,7 @@ bool save_player(int Ind)
 #ifdef VERIFY_SAVEFILE
 
 		/* Lock on savefile */
-		strcpy(temp, savefile);
+		strcpy(temp, p_ptr->savefile);
 		strcat(temp, ".lok");
 
 		/* Remove lock file */
