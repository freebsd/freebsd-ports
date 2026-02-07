--- editor.c.orig	1996-11-22 01:28:46 UTC
+++ editor.c
@@ -121,7 +121,7 @@ void DoEditWait();
 enum EditStates EditState;
 enum EditStates oldEditState;
 static int waitingFrame;
-enum EditStates waitMode;
+extern enum EditStates waitMode;
 static int oldWidth, oldHeight;
 static int curBlockType;
 static int drawAction = ED_NOP;
@@ -213,7 +213,7 @@ static void DoLoadLevel(display, window)
 
     /* Construct the Edit level filename */
     if ((str = getenv("XBOING_LEVELS_DIR")) != NULL)
-        sprintf(levelPath, "%s/editor.data", str);
+        snprintf(levelPath,sizeof(levelPath)-1, "%s/editor.data", str);
     else
         sprintf(levelPath, "%s/editor.data", LEVEL_INSTALL_DIR);
 
@@ -958,8 +958,8 @@ static void LoadALevel(display)
     if ((num > 0) && (num <= MAX_NUM_LEVELS))
     {
 	    /* Construct the Edit level filename */
-   	 	if ((str2 = getenv("XBOING_LEVELS_DIR")) != NULL)
-        	sprintf(levelPath, "%s/level%02ld.data", str2, (u_long) num);
+ 	if ((str2 = getenv("XBOING_LEVELS_DIR")) != NULL)
+        	snprintf(levelPath, sizeof(levelPath)-1,"%s/level%02ld.data", str2, (u_long) num);
     	else
         	sprintf(levelPath, "%s/level%02ld.data", 
 				LEVEL_INSTALL_DIR, (u_long) num);
@@ -1017,9 +1017,9 @@ static void SaveALevel(display)
     num = atoi(str);
     if ((num > 0) && (num <= MAX_NUM_LEVELS))
     {
-	    /* Construct the Edit level filename */
-   	 	if ((str2 = getenv("XBOING_LEVELS_DIR")) != NULL)
-        	sprintf(levelPath, "%s/level%02ld.data", str2, (u_long) num);
+        /* Construct the Edit level filename */
+ 	if ((str2 = getenv("XBOING_LEVELS_DIR")) != NULL)
+        	snprintf(levelPath, sizeof(levelPath)-1,"%s/level%02ld.data", str2, (u_long) num);
     	else
         	sprintf(levelPath, "%s/level%02ld.data", 
 				LEVEL_INSTALL_DIR, (u_long) num);
