--- highscore.c.orig	Thu Nov 20 03:07:35 1997
+++ highscore.c	Thu Nov 20 03:12:23 1997
@@ -55,6 +55,7 @@
 #include <time.h>
 #include <file.h>
 #include <sys/param.h>
+#include <sys/stat.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
 #include <X11/Xos.h>
@@ -119,7 +120,7 @@
 static void InitialiseHighScores(void);
 static void SortHighScores(void);
 static void DeleteScore(int i);
-static int LockUnlock(int cmd);
+static int LockUnlock(int cmd, int fd);
 #else
 static int LockUnlock();
 static void DeleteScore();
@@ -844,7 +845,7 @@
 
 	/* Lock the file for me only */
 	if (type == GLOBAL)
-		id = LockUnlock(LOCK_FILE);
+		id = LockUnlock(LOCK_FILE, -1);
 
 	/* Read in the lastest scores */
 	if (ReadHighScoreTable(type) == False)
@@ -875,8 +876,8 @@
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
@@ -898,16 +899,17 @@
 
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
@@ -1185,10 +1187,10 @@
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
@@ -1225,6 +1227,9 @@
 	/* Open the highscore file for both read & write */
 	if (cmd == LOCK_FILE)
 		inter = open(filename, O_CREAT | O_RDWR, 0666);
+	else
+		/* use old fd to unlock */
+		inter = fd;
 
 #ifndef NO_LOCKING
 
