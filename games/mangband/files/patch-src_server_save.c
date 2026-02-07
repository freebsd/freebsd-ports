--- src/server/save.c.orig	2021-02-18 22:20:24 UTC
+++ src/server/save.c
@@ -1109,7 +1109,7 @@ bool save_player(player_type *p_ptr)
 #ifdef VERIFY_SAVEFILE
 
 		/* Lock on savefile */
-		strcpy(temp, savefile);
+		strcpy(temp, p_ptr->savefile);
 		strcat(temp, ".lok");
 
 		/* Remove lock file */
