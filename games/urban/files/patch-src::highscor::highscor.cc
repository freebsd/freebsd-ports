--- src/highscor/highscor.cc.orig	Fri Sep  2 13:26:47 2005
+++ src/highscor/highscor.cc	Fri Sep  2 13:27:53 2005
@@ -75,7 +75,7 @@
 
 		if(highscore[i].Level)
 	        	sprintf(buffer, " %-10s%6d   %1d:%1d", highscore[i].Name,
-	        		highscore[i].Score, ((highscore[i].Level-1) / 3) + 1, ((highscore[i].Level-1) % 3) + 1);
+	        		highscore[i].Skore, ((highscore[i].Level-1) / 3) + 1, ((highscore[i].Level-1) % 3) + 1);
 		else
 	        	sprintf(buffer, " %-10s%6d   0:0", "Empty", 0);
 
@@ -100,7 +100,7 @@
 		strcpy(Name, "Unknown");
 #else
 		if(getenv("USER") != NULL)
-			strcpy(Name, getenv("USER"));
+	                strncpy(Name, getenv("USER"), sizeof(Name)-1);		
 		else
 			strcpy(Name, "Unknown");
 #endif
@@ -166,13 +166,13 @@
 
         for(int i = 0; i < NUM_HIGHSCORES; i++) {
 
-        	if(score > highscore[i].Score) {
+        	if(score > highscore[i].Skore) {
 
                 	memmove(&highscore[i + 1], &highscore[i],
                 		sizeof(Score_t) * (NUM_HIGHSCORES - i - 1));
 
                         strcpy(highscore[i].Name, GetName());
-                        highscore[i].Score = score;
+                        highscore[i].Skore = score;
                         highscore[i].Level = level;
                         break;
         	}
@@ -192,7 +192,7 @@
 #else
 	char filename[1024];
 
-	sprintf(filename, "%s/.urban/hs.dat", getenv("HOME"));
+        snprintf(filename, sizeof(filename)-1, "%s/.urban/hs.dat", getenv("HOME"));
 
         if((fd = fopen(filename, "rb")) == NULL)
 #endif
@@ -215,11 +215,10 @@
 	char filename[1024];
 
 	/* Create dir */
-	sprintf(filename, "%s/.urban", getenv("HOME"));
+	snprintf(filename, sizeof(filename)-1, "%s/.urban", getenv("HOME"));
 	mkdir(filename, S_IRUSR | S_IWUSR | S_IXUSR);
 
-	sprintf(filename, "%s/.urban/hs.dat", getenv("HOME"));
-
+        snprintf(filename, sizeof(filename)-1, "%s/.urban/hs.dat", getenv("HOME"));
         if((fd = fopen(filename, "wb")) == NULL)
 #endif
 #endif
