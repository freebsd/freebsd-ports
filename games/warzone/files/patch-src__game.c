--- src/game.c.bak	Thu Aug 17 18:52:11 2006
+++ src/game.c	Thu Aug 17 18:52:44 2006
@@ -2832,7 +2832,7 @@
 	aFileName[strlen(aFileName) - 4] = '\0';
 
 	//create dir will fail if directory already exists but don't care!
-	(void) PHYSFS_mkdir(aFileName);
+	(void) PHYSFS_mkdir(unix_path(aFileName));
 
 	//save the map file
 	strcat(aFileName, "/");
