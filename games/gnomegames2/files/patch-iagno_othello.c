--- iagno/othello.c.orig	Mon Feb 14 12:07:12 2005
+++ iagno/othello.c	Mon Feb 14 12:07:47 2005
@@ -551,7 +551,7 @@
 					memcpy (tboard, board, sizeof (gint8) * 8 * 8);
 					move_board(tboard, i, j, me, 0);
 	
-					// assume that opponent takes best move
+					/* assume that opponent takes best move */
 					tmp_move = find_best_move(tboard, not_me, ply_depth-1,
 						-pass_thresh, -use_thresh, 0, 0);
 
@@ -808,14 +808,14 @@
 				found_free = TRUE;
 		}
 		
-	// check if a player is dead
+	/* check if a player is dead */
 	if (!found_me && found_not_me)
 		return (-10000);
 	else if (found_me && !found_not_me)
 		return (10000);
 	
-	// if the game is finished, return the actual score rather than
-	// a huristic
+	/* if the game is finished, return the actual score rather than
+	   a huristic */
 	if (!found_free)
 		return (actual_score);
 	
