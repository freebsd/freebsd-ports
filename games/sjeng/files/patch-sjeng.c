--- sjeng.c.orig	2001-12-27 22:20:38 UTC
+++ sjeng.c
@@ -36,7 +36,7 @@ char divider[50] = "----------------------------------
 move_s dummy = {0,0,0,0,0};
 
 int board[144], moved[144], ep_square, white_to_move, comp_color, wking_loc,
-  bking_loc, white_castled, black_castled, result, ply, pv_length[PV_BUFF],
+  bking_loc, white_castled, black_castled, result, pv_length[PV_BUFF],
   pieces[62], squares[144], num_pieces, i_depth, fifty, piece_count;
 
 long int nodes, raw_nodes, qnodes,  killer_scores[PV_BUFF],
