--- file.c.orig	1996-11-22 01:28:46 UTC
+++ file.c
@@ -139,7 +139,7 @@ void SetupStage(display, window)
 
     /* Construct the level filename */
     if ((str = getenv("XBOING_LEVELS_DIR")) != NULL)
-        sprintf(levelPath, "%s/level%02ld.data", str, newLevel);
+        snprintf(levelPath,sizeof(levelPath), "%s/level%02ld.data", str, newLevel);
     else
         sprintf(levelPath, "%s/level%02ld.data", LEVEL_INSTALL_DIR, newLevel);
 
@@ -177,7 +177,7 @@ int LoadSavedGame(display, window)
     static int bgrnd = 1;
 
 	/* Save the file in home directory - construct path */
-	sprintf(levelPath, "%s/.xboing-saveinfo", GetHomeDir());
+	snprintf(levelPath, sizeof(levelPath)-1, "%s/.xboing-saveinfo", GetHomeDir());
 
     /* Open the save file info for reading */
     if ((saveFile = fopen(levelPath, "r+")) == NULL)
@@ -239,7 +239,7 @@ int LoadSavedGame(display, window)
     DisplayLevelInfo(display, levelWindow, level);
 
 	/* Load the saved file in home directory - construct path */
-	sprintf(levelPath, "%s/.xboing-savelevel", GetHomeDir());
+	snprintf(levelPath, sizeof(levelPath)-1, "%s/.xboing-savelevel", GetHomeDir());
 
 	/* Read in the saved level data */
     if (ReadNextLevel(display, window, levelPath, True) == False)
@@ -283,7 +283,7 @@ int SaveCurrentGame(display, window)
 	saveGame.numBullets	= GetNumberBullets();
 
 	/* Save the file in home directory - construct path */
-	sprintf(levelPath, "%s/.xboing-saveinfo", GetHomeDir());
+	snprintf(levelPath, sizeof(levelPath)-1, "%s/.xboing-saveinfo", GetHomeDir());
 
     /* Open the save file info for writing */
     if ((saveFile = fopen(levelPath, "w+")) == NULL)
@@ -309,7 +309,7 @@ int SaveCurrentGame(display, window)
     	WarningMessage("Cannot close save game info file.");
 
 	/* Save the file in home directory - construct path */
-	sprintf(levelPath, "%s/.xboing-savelevel", GetHomeDir());
+	snprintf(levelPath, sizeof(levelPath)-1, "%s/.xboing-savelevel", GetHomeDir());
 
 	if (SaveLevelDataFile(display, levelPath) == True)
 	{
