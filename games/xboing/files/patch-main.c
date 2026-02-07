--- main.c.orig	1996-11-22 01:28:46 UTC
+++ main.c
@@ -156,7 +156,7 @@ void SetUserSpeed(delay)
 
 	/* Set an entire game speedup or slowdown speed */
 	temp = (speed / (long) userDelay);
-	userDelay = delay;
+	userDelay = delay/2 + 3;
 	speed = (long) (temp * userDelay);
 	speedLevel = 10 - delay;
 }
