--- iagno/othello.c.orig	Thu May 20 17:20:21 2004
+++ iagno/othello.c	Thu May 20 17:21:11 2004
@@ -544,7 +544,7 @@
 					memcpy (tboard, board, sizeof (gint8) * 8 * 8);
 					move_board(tboard, i, j, me, 0);
 	
-					// assume that opponent takes best move
+					/* assume that opponent takes best move */
 					tmp_move = find_best_move(tboard, not_me, ply_depth-1,
 						-pass_thresh, -use_thresh, 0, 0);
 
@@ -559,7 +559,7 @@
 					}
 				}
 		
-		// check if we have to pass
+		/* check if we have to pass */
 		if (best_x == 8 && best_y == 8) {
 			tmp_move = find_best_move(board, not_me, ply_depth-1,
 				-pass_thresh, -use_thresh, 0, 0);
@@ -802,14 +802,14 @@
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
+	 * a huristic */
 	if (!found_free)
 		return (actual_score);
 	
