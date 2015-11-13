--- src/ShiftyEngine.c.orig	2004-09-21 01:08:59 UTC
+++ src/ShiftyEngine.c
@@ -93,7 +93,7 @@ void SE_SetBackground(char * name)
 		exit(1);
 	}
 
-	strncpy(backgroundName, name, len);
+	strncpy(backgroundName, name, len + 1);
 }
 
 /*****************************************************
