--- highscore.c.orig	1996-11-22 01:28:46 UTC
+++ highscore.c
@@ -55,6 +55,7 @@
 #include <time.h>
 #include <file.h>
 #include <sys/param.h>
+#include <sys/stat.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
 #include <X11/Xos.h>
@@ -119,7 +120,7 @@ static void SetHighScoreWait(enum HighScoreStates newM
 static void InitialiseHighScores(void);
 static void SortHighScores(void);
 static void DeleteScore(int i);
-static int LockUnlock(int cmd);
+static int LockUnlock(int cmd, int fd);
 #else
 static int LockUnlock();
 static void DeleteScore();
@@ -137,7 +138,7 @@ static int endFrame = 0;
 enum HighScoreStates HighScoreState;
 static Pixmap titlePixmap, titlePixmapM;
 static int waitingFrame;
-enum HighScoreStates waitMode;
+extern enum HighScoreStates waitMode;
 static int sparkley = 0;
 static int sindex = 0;
 static int si = 0;
@@ -844,7 +845,7 @@ int CheckAndAddScoreToHighScore(score, level, gameTime
 
 	/* Lock the file for me only */
 	if (type == GLOBAL)
-		id = LockUnlock(LOCK_FILE);
+		id = LockUnlock(LOCK_FILE, -1);
 
 	/* Read in the lastest scores */
 	if (ReadHighScoreTable(type) == False)
@@ -875,8 +876,8 @@ int CheckAndAddScoreToHighScore(score, level, gameTime
 				{
 					/* Don't add as score is smaller */
 					if (id != -1) 
-						id = LockUnlock(UNLOCK_FILE);
-					return False;
+						id = LockUnlock(UNLOCK_FILE, id);
+					goto doUnlock;
 				}
 			}
 		}	/* for */
@@ -898,16 +899,17 @@ int CheckAndAddScoreToHighScore(score, level, gameTime
 
 				/* Unlock the file now thanks */
 				if (id != -1) 
-					id = LockUnlock(UNLOCK_FILE);
+					id = LockUnlock(UNLOCK_FILE, id);
 
 				/* Yes - it was placed in the highscore */
 				return True;
 			}
 		}
 
+doUnlock:
 		/* Unlock the file now thanks */
 		if (id != -1) 
-			id = LockUnlock(UNLOCK_FILE);
+			id = LockUnlock(UNLOCK_FILE, id);
 
 		/* Not even a highscore - loser! */
 		return False;
@@ -1023,7 +1025,7 @@ int ReadHighScoreTable(type)
 	{
 		/* Use the environment variable if it exists */
 		if ((str = getenv("XBOING_SCORE_FILE")) != NULL)
-			strcpy(filename, str);
+			strncpy(filename, str, sizeof(filename)-1);
 		else
 			strcpy(filename, HIGH_SCORE_FILE);
 	}
@@ -1095,7 +1097,7 @@ int WriteHighScoreTable(type)
 	{
 		/* Use the environment variable if it exists */
 		if ((str = getenv("XBOING_SCORE_FILE")) != NULL)
-			strcpy(filename, str);
+			strncpy(filename, str, sizeof(filename)-1);
 		else
 			strcpy(filename, HIGH_SCORE_FILE);
 	}	
@@ -1185,10 +1187,10 @@ void ResetHighScore(type)
 }
 
 #if NeedFunctionPrototypes
-static int LockUnlock(int cmd)
+static int LockUnlock(int cmd, int fd)
 #else
 static int LockUnlock(cmd)
-	int cmd;
+	int cmd, fd;
 #endif
 {
 	static int 	inter = -1;
@@ -1218,13 +1220,16 @@ static int LockUnlock(cmd)
 
 	/* Use the environment variable if it exists */
 	if ((str = getenv("XBOING_SCORE_FILE")) != NULL)
-		strcpy(filename, str);
+		strncpy(filename, str, sizeof(filename)-1);
 	else
 		strcpy(filename, HIGH_SCORE_FILE);
 
 	/* Open the highscore file for both read & write */
 	if (cmd == LOCK_FILE)
 		inter = open(filename, O_CREAT | O_RDWR, 0666);
+	else
+		/* use old fd to unlock */
+		inter = fd;
 
 #ifndef NO_LOCKING
 
