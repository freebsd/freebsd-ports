--- mapedit.cpp.orig	2007-11-06 00:24:09.000000000 +0100
+++ mapedit.cpp	2007-11-06 00:24:48.000000000 +0100
@@ -405,22 +405,22 @@
 	}
 	if( ! (flags & SEEN_START) )
 	{
-		errScroll.render_string( "Start Tile Needed", 300, 0 );
+		errScroll.render_string((char *) "Start Tile Needed", 300, 0 );
 	}
 
 	if( ! (flags & SEEN_SPINNER) )
 	{
-		errScroll.render_string( "Spinner Needed", 300, 10 );
+		errScroll.render_string((char *) "Spinner Needed", 300, 10 );
 	}
 
 	if( (leftCount % 2) || (upCount % 2) )
 	{
-		errScroll.render_string( "Unmatched Teleporters", 300, 20 );
+		errScroll.render_string((char *) "Unmatched Teleporters", 300, 20 );
 	}
 
 	if( (leftCount > 2) || (upCount > 2) )
 	{
-		errScroll.render_string( "Too Many Teleporters", 450, 0 );
+		errScroll.render_string((char *) "Too Many Teleporters", 450, 0 );
 	}
 
 	sprintf( cstr, "MAP NAME: %s", CURMAP->mapName );
@@ -481,13 +481,13 @@
 	{
 
 		graphDriver->graph_hi_font( )->
-			render_string("UP",
+			render_string((char *) "UP",
 			NUM_COLS*TILESIZE + MENU_SEP + 60,
 			TOP_MAP_OFFSET + SPACER + 15 );
 	} else {
 		// Draw the label
 		graphDriver->graph_lo_font( )->
-			render_string("UP",
+			render_string((char *) "UP",
 			NUM_COLS*TILESIZE + MENU_SEP + 60,
 			TOP_MAP_OFFSET + SPACER + 15 );
 	}
@@ -497,13 +497,13 @@
 	{
 		// Draw the label
 		graphDriver->graph_hi_font( )->
-			render_string("DOWN",
+			render_string((char *) "DOWN",
 			NUM_COLS*TILESIZE+MENU_SEP + 27,
 			MENU_NUM_ROWS*TILESIZE + MENU_Y_OFFSET + SPACER + 13);
 	} else {
 		// Draw the label
 		graphDriver->graph_lo_font( )->
-			render_string("DOWN",
+			render_string((char *) "DOWN",
 			NUM_COLS*TILESIZE+MENU_SEP + 27,
 			MENU_NUM_ROWS*TILESIZE + MENU_Y_OFFSET + SPACER + 13);
 	}
@@ -682,7 +682,7 @@
 		5 );
 
 	graphDriver->graph_hi_font( )->
-		render_string("MAP",
+		render_string((char *) "MAP",
 		NUM_COLS*TILESIZE + MENU_SEP + 43,
 		0 );
 
@@ -698,7 +698,7 @@
 	graphDriver->graph_draw( BMP_BALL_C2,
 		NUM_COLS*TILESIZE - 150,
 		NUM_ROWS * TILESIZE + 39 );
-	errScroll.render_string( "Quit WITHOUT Saving",
+	errScroll.render_string((char *) "Quit WITHOUT Saving",
 		NUM_COLS*TILESIZE  - 150 + 20,
 		NUM_ROWS * TILESIZE + 44 );
 
@@ -706,7 +706,7 @@
 	graphDriver->graph_draw( BMP_BALL_C2,
 		NUM_COLS*TILESIZE + 60,
 		NUM_ROWS * TILESIZE + 39);
-	errScroll.render_string( "Quit And Save",
+	errScroll.render_string((char *) "Quit And Save",
 		NUM_COLS*TILESIZE + 80,
 		NUM_ROWS * TILESIZE + 44 );
 }	
