--- tetris.h.orig	2003-09-07 16:29:29 UTC
+++ tetris.h
@@ -50,7 +50,7 @@ typedef struct {
     char shape[4][4];	/* Shape data for the piece */
 } PieceData;
 
-PieceData piecedata[7][4];
+extern PieceData piecedata[7][4];
 
 extern int current_piece, current_rotation;
 
