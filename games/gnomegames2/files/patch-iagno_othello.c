--- iagno/othello.c.orig	Tue Jan 25 11:24:35 2005
+++ iagno/othello.c	Tue Jan 25 11:24:56 2005
@@ -784,14 +784,14 @@
 				found_free = TRUE;
 		}
 		
-	// check if a player is dead
+	/* check if a player is dead */
 	if (!found_me && found_not_me)
 		return (S_LOSING_GAME);
 	else if (found_me && !found_not_me)
 		return (S_WINNING_GAME);
 	
-	// if the game is finished, return the actual score rather than
-	// a huristic
+	/* if the game is finished, return the actual score rather than
+	 * a huristic */
 	if (!found_free)
 		return (actual_score);
 	
