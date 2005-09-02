--- src/engine/game.cc.orig	Fri Sep  2 13:26:28 2005
+++ src/engine/game.cc	Fri Sep  2 13:27:53 2005
@@ -93,10 +93,10 @@
 char *demo_filename;
 
 struct PlayerData DefaultPData = {
-	{3},
+	3,
 	{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
-        {300}, {0}
+        300, 0
 };
 
 
@@ -263,7 +263,7 @@
 #ifdef DJGPP
 	sprintf(filename, "savegame.dat");
 #else
-	sprintf(filename, "%s/.urban/savegame.dat", getenv("HOME"));
+	snprintf(filename, sizeof(filename)-1, "%s/.urban/savegame.dat", getenv("HOME"));
 #endif
 
         if ((fs = fopen(filename, "rb")) == NULL) {
@@ -275,10 +275,10 @@
                 }
 #ifndef DJGPP
 		/* Create dir */
-		sprintf(filename, "%s/.urban", getenv("HOME"));
+		snprintf(filename, sizeof(filename)-1, "%s/.urban", getenv("HOME"));
 		mkdir(filename, S_IRUSR | S_IWUSR | S_IXUSR);
 
-		sprintf(filename, "%s/.urban/savegame.dat", getenv("HOME"));
+		snprintf(filename, sizeof(filename)-1, "%s/.urban/savegame.dat", getenv("HOME"));
 #endif
                 if((fs = fopen(filename, "wb")) == NULL)
 	        	fwrite(SavedGames, 1, 5 * sizeof(struct SaveGameData), fs);
@@ -338,10 +338,10 @@
 						sprintf(filename, "savegame.dat");
 #else
 						/* Create dir */
-						sprintf(filename, "%s/.urban", getenv("HOME"));
+						snprintf(filename, sizeof(filename)-1, "%s/.urban", getenv("HOME"));
 						mkdir(filename, S_IRUSR | S_IWUSR | S_IXUSR);
 
-						sprintf(filename, "%s/.urban/savegame.dat", getenv("HOME"));
+						snprintf(filename, sizeof(filename)-1, "%s/.urban/savegame.dat", getenv("HOME"));
 #endif
 					        if ((fs = fopen(filename, "wb")) != NULL) {
 					        	fwrite(SavedGames, 1, 5 * sizeof(struct SaveGameData), fs);
