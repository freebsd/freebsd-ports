--- src/highscor/highscor.cc.orig	Sun Jan 25 03:58:07 2004
+++ src/highscor/highscor.cc	Sun Jan 25 03:58:30 2004
@@ -75,7 +75,7 @@
 
 		if(highscore[i].Level)
 	        	sprintf(buffer, " %-10s%6d   %1d:%1d", highscore[i].Name,
-	        		highscore[i].Score, ((highscore[i].Level-1) / 3) + 1, ((highscore[i].Level-1) % 3) + 1);
+	        		highscore[i].Skore, ((highscore[i].Level-1) / 3) + 1, ((highscore[i].Level-1) % 3) + 1);
 		else
 	        	sprintf(buffer, " %-10s%6d   0:0", "Empty", 0);
 
@@ -166,13 +166,13 @@
 
         for(int i = 0; i < NUM_HIGHSCORES; i++) {
 
-        	if(score > highscore[i].Score) {
+        	if(score > highscore[i].Skore) {
 
                 	memmove(&highscore[i + 1], &highscore[i],
                 		sizeof(Score) * (NUM_HIGHSCORES - i - 1));
 
                         strcpy(highscore[i].Name, GetName());
-                        highscore[i].Score = score;
+                        highscore[i].Skore = score;
                         highscore[i].Level = level;
                         break;
         	}
