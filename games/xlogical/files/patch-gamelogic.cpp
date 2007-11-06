--- gamelogic.cpp.orig	2001-08-01 02:59:40.000000000 +0200
+++ gamelogic.cpp	2007-11-05 23:50:06.000000000 +0100
@@ -1,4 +1,4 @@
-//////////////////////////////////////////////////////////////////////
+/////////////////////////////////////////////////////////////////////
 // XLogical - A puzzle game
 //
 // Copyright (C) 2000 Neil Brown, Tom Warkentin
@@ -154,7 +154,7 @@
 		levelFile = NULL;
 	}
 
-	currentMap = NULL;
+	currentMap = gameLevels.end( );
 
 	playerName = new char[32+1];
 	strcpy( playerName, "nobody" );
@@ -193,14 +193,14 @@
 	livesLeft = 3;
 
 	modScroller.set_bounds( 32, 256, 40 );
-	modScroller.set_string( " " );
+	modScroller.set_string((char *) " " );
 
 	infoScroller.set_bounds( 384, 607, 40 );
-	infoScroller.set_string( " " );
+	infoScroller.set_string((char *) " " );
 	read_hiscores( );
 
 	scrFont.set_font_info( BMP_FONT_3, scrFontWidths, 26, 2, ' ', '`' );
-	infoScroller.set_string( " " );
+	infoScroller.set_string((char *) " " );
 }
 
 
@@ -1441,7 +1441,7 @@
 	static int renderLineAbout = 0;
 	static int blankLineAbout = 0;
 
-	static char *credits[] = {
+	static const char *credits[] = {
 		"XLOGICAL",
 		" ",
 		" ",
@@ -1505,7 +1505,7 @@
 		// Blink on and off here.
 		if( blinker )
 		{
-			scrFont.render_string_center( "BALL TIMEOUT", 0, PLAYWIDTH, 50 );
+			scrFont.render_string_center((char *) "BALL TIMEOUT", 0, PLAYWIDTH, 50 );
 		}
 		break;
 	case MAP_TIMEOUT:
@@ -1516,15 +1516,14 @@
 			graphDriver->graph_main_height() );
 		if( blinker )
 		{
-			scrFont.render_string_center( "OUT OF TIME", 0, PLAYWIDTH, 50 );
+			scrFont.render_string_center((char *) "OUT OF TIME", 0, PLAYWIDTH, 50 );
 		}
 		break;
 	case WON:
 		// Blink our congrats
 		if( blinker )
 		{
-			scrFont.render_string_center( 
-					"CONGRATULATIONS!!  YOU WON", 0, PLAYWIDTH, 50 );
+			scrFont.render_string_center((char *) "CONGRATULATIONS!!  YOU WON", 0, PLAYWIDTH, 50 );
 		} else {
 
 			// Clear the blinker area
@@ -1536,7 +1535,7 @@
 
 		if (gEnteringHiScore)
 		{
-			scrFont.render_string_center("ENTER YOUR NAME", 0, PLAYWIDTH, 200);
+			scrFont.render_string_center((char *) "ENTER YOUR NAME", 0, PLAYWIDTH, 200);
 			static int wonBlinkCount = 3;
 			static bool wonOnOffFlag = true;
 			if (wonBlinkCount <= 0)
@@ -1558,7 +1557,7 @@
 			{
 				int len = scrFont.stringLen( buf );
 				int x = (PLAYWIDTH - len ) / 2 + len;
-				scrFont.render_string( "-", x, 250 );
+				scrFont.render_string((char *) "-", x, 250 );
 			}
 		} else {
 
@@ -1577,7 +1576,7 @@
 				// We're not on the last line yet so keep drawing stuff
 				// Draw our line of text starting at the bottom
 				scrFont.render_string_center( 
-					credits[renderLine], 0, PLAYWIDTH,  
+					(char *)credits[renderLine], 0, PLAYWIDTH,  
 					CREDITS_SCROLL_BASE + CREDITS_SCROLL_HEIGHT - scrollPixSkip );
 			}
 
@@ -1620,20 +1619,20 @@
 			graphDriver->graph_main_width(),
 			graphDriver->graph_main_height() );
 		// Do some scoring here.....
-		scrFont.render_string_center( "WELL DONE", 0, PLAYWIDTH, 5 );
-		scrFont.render_string_center( "LEVEL COMPLETED", 0, PLAYWIDTH, 50 );
-		scrFont.render_string( "SPINNERS", 50, 150 );
+		scrFont.render_string_center((char *) "WELL DONE", 0, PLAYWIDTH, 5 );
+		scrFont.render_string_center((char *) "LEVEL COMPLETED", 0, PLAYWIDTH, 50 );
+		scrFont.render_string((char *) "SPINNERS", 50, 150 );
 
 		sprintf( cstr, "%d", CURMAP->spinnersOnMap );
 		scrFont.render_string_rjust( cstr, PLAYWIDTH - 50 , 150 );
 
 		if( CURMAP->haveMapTimer )
 		{
-			scrFont.render_string( "SECONDS LEFT", 50, 200 );
+			scrFont.render_string((char *) "SECONDS LEFT", 50, 200 );
 			sprintf( cstr, "%ld", spareTime / kTicksInSecond );
 			scrFont.render_string_rjust( cstr, PLAYWIDTH - 50, 200 );
 
-			scrFont.render_string( "TIME BONUS", 50, 250 );
+			scrFont.render_string((char *) "TIME BONUS", 50, 250 );
 			sprintf( cstr, "%ld", currentGame->bonus );
 			scrFont.render_string_rjust( cstr, PLAYWIDTH - 50, 250 );
 
@@ -1652,12 +1651,12 @@
 				currentGame->bonus = 0;
 			}
 		} else {
-			scrFont.render_string( "NO TIME LIMIT", 50, 200 );
-			scrFont.render_string( "NO TIME BONUS", 50, 250 );
+			scrFont.render_string((char *) "NO TIME LIMIT", 50, 200 );
+			scrFont.render_string((char *) "NO TIME BONUS", 50, 250 );
 			currentGame->bonus = 0;
 		}
 
-		scrFont.render_string( "SCORE", 50, 300 );
+		scrFont.render_string((char *) "SCORE", 50, 300 );
 		sprintf( cstr, "%ld", currentGame->score );
 		scrFont.render_string_rjust( cstr, PLAYWIDTH - 50, 300 );
 
@@ -1676,12 +1675,12 @@
 		sprintf( cstr, "%s", (*currentGame->currentMap)->mapName );
 		scrFont.render_string_center( cstr, 5, PLAYWIDTH - 5, 20 );
 
-		scrFont.render_string( "PASSWORD" , 50, 100 );
+		scrFont.render_string((char *) "PASSWORD" , 50, 100 );
 		sprintf( cstr, "%s", encrypt(
 			(*currentGame->currentMap)->mapName, currentGame->encryptName ) );
 		scrFont.render_string_rjust( cstr, PLAYWIDTH - 50, 100 );
 
-		scrFont.render_string( "SPINNERS" , 50, 150 );
+		scrFont.render_string((char *) "SPINNERS" , 50, 150 );
 		sprintf( cstr, "%d", CURMAP->spinnersOnMap );
 		scrFont.render_string_rjust( cstr, PLAYWIDTH - 50, 150 );
 
@@ -1690,23 +1689,23 @@
 			long totalSecs = CURMAP->mapTimeLimit / kTicksInSecond;
 			long mins = totalSecs / 60;
 			long secs = totalSecs % 60;
-			scrFont.render_string( "MAP TIME" , 50, 200 );
+			scrFont.render_string((char *) "MAP TIME" , 50, 200 );
 			sprintf( cstr, "%02ld:%02ld", mins, secs );
 			scrFont.render_string_rjust( cstr, PLAYWIDTH - 50, 200 );
 		} else {
-			scrFont.render_string( "NO TIME LIMIT" , 50, 200 );
+			scrFont.render_string((char *) "NO TIME LIMIT" , 50, 200 );
 		}
 
 		{
 			long totalSecs = CURMAP->ballTimeLimit / kTicksInSecond;
 			long mins = totalSecs / 60;
 			long secs = totalSecs % 60;
-			scrFont.render_string( "BALL TIME" , 50, 250 );
+			scrFont.render_string((char *) "BALL TIME" , 50, 250 );
 			sprintf( cstr, "%02ld:%02ld", mins, secs );
 			scrFont.render_string_rjust( cstr, PLAYWIDTH - 50, 250 );
 		}
 
-		scrFont.render_string( "LIVES LEFT" , 50, 300 );
+		scrFont.render_string((char *) "LIVES LEFT" , 50, 300 );
 		sprintf( cstr, "%d", currentGame->livesLeft );
 		scrFont.render_string_rjust( cstr, PLAYWIDTH - 50, 300 );
 
@@ -1717,10 +1716,10 @@
 			0, 0,
 			graphDriver->graph_main_width(),
 			graphDriver->graph_main_height() );
-		scrFont.render_string_center( "GAME OVER", 0, PLAYWIDTH, 50 );
+		scrFont.render_string_center((char *) "GAME OVER", 0, PLAYWIDTH, 50 );
 		if (gEnteringHiScore)
 		{
-			scrFont.render_string_center("ENTER YOUR NAME", 0, PLAYWIDTH, 200);
+			scrFont.render_string_center((char *) "ENTER YOUR NAME", 0, PLAYWIDTH, 200);
 			static int blinkCount = 3;
 			static bool onOffFlag = true;
 			if (blinkCount <= 0)
@@ -1737,7 +1736,7 @@
 			{
 				int len = scrFont.stringLen( buf );
 				int x = (PLAYWIDTH - len ) / 2 + len;
-				scrFont.render_string( "-", x, 250 );
+				scrFont.render_string((char *) "-", x, 250 );
 			}
 		}
 		break;
@@ -1747,7 +1746,7 @@
 			0, 0,
 			graphDriver->graph_main_width(),
 			graphDriver->graph_main_height() );
-		scrFont.render_string_center( "HIGH SCORES", 0, PLAYWIDTH, 10 );
+		scrFont.render_string_center((char *) "HIGH SCORES", 0, PLAYWIDTH, 10 );
 
 		// Draw the high scores
 		for( i = 0; i < NUM_HI_SCORES; i++ )
@@ -1760,24 +1759,24 @@
 		}
 		break;
 	case ABOUT:
-		scrFont.render_string_center( "ABOUT XLOGICAL", 0, PLAYWIDTH, 30 );
+		scrFont.render_string_center((char *) "ABOUT XLOGICAL", 0, PLAYWIDTH, 30 );
 		j = 100;
-		scrFont.render_string( "CODERS", 50, j );
-		scrFont.render_string_rjust( "NEIL BROWN", PLAYWIDTH - 50, j );
+		scrFont.render_string((char *) "CODERS", 50, j );
+		scrFont.render_string_rjust((char *) "NEIL BROWN", PLAYWIDTH - 50, j );
 		j += 35;
-		scrFont.render_string_rjust( "TOM WARKENTIN", PLAYWIDTH - 50, j );
+		scrFont.render_string_rjust((char *) "TOM WARKENTIN", PLAYWIDTH - 50, j );
 		j += 35;
 		j += 35;
-		scrFont.render_string( "GRAPHICS", 50, j );
-		scrFont.render_string_rjust( "SLOANE MUSCROFT", PLAYWIDTH - 50, j );
+		scrFont.render_string((char *) "GRAPHICS", 50, j );
+		scrFont.render_string_rjust((char *) "SLOANE MUSCROFT", PLAYWIDTH - 50, j );
 
-		modScroller.render_string_center( 
+		modScroller.render_string_center((char *) 
 				"XLOGICAL V1.0 COPYRIGHT (C) 2000 NEIL BROWN, TOM WARKENTIN", 
 				0, PLAYWIDTH, 280 );
-		modScroller.render_string_center( 
+		modScroller.render_string_center((char *) 
 				"XLOGICAL COMES WITH ABSOLUTELY NO WARRANTY;", 
 				0, PLAYWIDTH, 290 );
-		modScroller.render_string_center( 
+		modScroller.render_string_center((char *) 
 				"XLOGICAL IS DISTRIBUTED UNDER THE GNU PUBLIC LICENSE", 
 				0, PLAYWIDTH, 300 );
 
@@ -1796,7 +1795,7 @@
 			1 );
 
 
-		modScroller.render_string_center( 
+		modScroller.render_string_center((char *) 
 				"GNU PUBLIC LICENSE", 
 				0, PLAYWIDTH, LICENSE_SCROLL_BASE - 13 );
 
@@ -1815,7 +1814,7 @@
 			// We're not on the last line yet so keep drawing stuff
 			// Draw our line of text starting at the bottom
 			modScroller.render_string_center( 
-				gpl[renderLineAbout], 0, PLAYWIDTH,  
+				(char *)gpl[renderLineAbout], 0, PLAYWIDTH,  
 				LICENSE_SCROLL_BASE + LICENSE_SCROLL_HEIGHT - scrollPixSkipAbout );
 		}
 
@@ -1870,12 +1869,12 @@
 			0, 0,
 			graphDriver->graph_main_width(),
 			graphDriver->graph_main_height() );
-		scrFont.render_string_center( "HOW DID YOU GET HERE???", 0, 
+		scrFont.render_string_center((char *) "HOW DID YOU GET HERE???", 0, 
 														PLAYWIDTH, 40 );
 		break;
 	}
 
-	scrFont.render_string_center( "PRESS SPACE TO CONTINUE", 0, PLAYWIDTH, 440 );
+	scrFont.render_string_center((char *) "PRESS SPACE TO CONTINUE", 0, PLAYWIDTH, 440 );
 }
 
 
@@ -1891,28 +1890,28 @@
 		graphDriver->graph_main_width(),
 		graphDriver->graph_main_height() );
 
-	scrFont.render_string_center( "HOW TO PLAY", 0, PLAYWIDTH, 5 );
+	scrFont.render_string_center((char *) "HOW TO PLAY", 0, PLAYWIDTH, 5 );
 
 	xoff = 10;
 	yoff = 50;
 	graphDriver->graph_draw( BMP_BACK_GAME, xoff, yoff );
 	graphDriver->graph_draw( BMP_TELEPORT_BASE, xoff, yoff );
 	graphDriver->graph_draw( BMP_TELEPORT_UD, xoff, yoff );
-	modScroller.render_string( "-- Teleporter --", xoff+70, yoff+5 );
-	modScroller.render_string( "The ball will be", xoff+70, yoff+15 );
-	modScroller.render_string( "transported to", xoff+70, yoff+ 25 );
-	modScroller.render_string( "the matching", xoff+70, yoff+35);
-	modScroller.render_string( "teleporter tile.", xoff+70, yoff+45 );
+	modScroller.render_string((char *) "-- Teleporter --", xoff+70, yoff+5 );
+	modScroller.render_string((char *) "The ball will be", xoff+70, yoff+15 );
+	modScroller.render_string((char *) "transported to", xoff+70, yoff+ 25 );
+	modScroller.render_string((char *) "the matching", xoff+70, yoff+35);
+	modScroller.render_string((char *) "teleporter tile.", xoff+70, yoff+45 );
 
 	yoff += 70 ;
 	graphDriver->graph_draw( BMP_BACK_GAME, xoff, yoff );
 	graphDriver->graph_draw( BMP_BALLMOVE5_5, xoff + 12, yoff + 5 );
-	modScroller.render_string( "--Moving Balls--", xoff+70, yoff+5 );
-	modScroller.render_string( "Colored bars show", xoff+70, yoff+15 );
-	modScroller.render_string( "how many balls are", xoff+70, yoff+ 25 );
-	modScroller.render_string( "in motion. When it", xoff+70, yoff+35);
-	modScroller.render_string( "is full, no more", xoff+70, yoff+45 );
-	modScroller.render_string( "balls can be moved.", xoff+70, yoff+55 );
+	modScroller.render_string((char *) "--Moving Balls--", xoff+70, yoff+5 );
+	modScroller.render_string((char *) "Colored bars show", xoff+70, yoff+15 );
+	modScroller.render_string((char *) "how many balls are", xoff+70, yoff+ 25 );
+	modScroller.render_string((char *) "in motion. When it", xoff+70, yoff+35);
+	modScroller.render_string((char *) "is full, no more", xoff+70, yoff+45 );
+	modScroller.render_string((char *) "balls can be moved.", xoff+70, yoff+55 );
 
 	yoff += 70 ;
 	graphDriver->graph_draw( BMP_BACK_GAME, xoff, yoff );
@@ -1921,11 +1920,11 @@
 	graphDriver->graph_draw( BMP_GEM_C2, xoff + 43, yoff + 23 );
 	graphDriver->graph_draw( BMP_GEM_C3, xoff + 23, yoff + 42 );
 	graphDriver->graph_draw( BMP_GEM_C4, xoff + 2, yoff + 23 );
-	modScroller.render_string( "--Pattern--", xoff+70, yoff+5 );
-	modScroller.render_string( "Shows the colors", xoff+70, yoff+15 );
-	modScroller.render_string( "of the balls in", xoff+70, yoff+ 25 );
-	modScroller.render_string( "a spinner for it", xoff+70, yoff+35);
-	modScroller.render_string( "to be completed.", xoff+70, yoff+45 );
+	modScroller.render_string((char *) "--Pattern--", xoff+70, yoff+5 );
+	modScroller.render_string((char *) "Shows the colors", xoff+70, yoff+15 );
+	modScroller.render_string((char *) "of the balls in", xoff+70, yoff+ 25 );
+	modScroller.render_string((char *) "a spinner for it", xoff+70, yoff+35);
+	modScroller.render_string((char *) "to be completed.", xoff+70, yoff+45 );
 	xoff = 235;
 	yoff = 50 ;
 	graphDriver->graph_draw( BMP_BACK_GAME, xoff, yoff );
@@ -1933,98 +1932,98 @@
 	graphDriver->graph_draw( BMP_GEM_C1, xoff + 23, yoff + 4 );
 	graphDriver->graph_draw( BMP_GEM_C2, xoff + 23, yoff + 23 );
 	graphDriver->graph_draw( BMP_GEM_C3, xoff + 23, yoff + 42 );
-	modScroller.render_string( "--Order--", xoff+70, yoff+5 );
-	modScroller.render_string( "Shows which", xoff+70, yoff+15 );
-	modScroller.render_string( "color balls", xoff+70, yoff+ 25 );
-	modScroller.render_string( "to fill the", xoff+70, yoff+35);
-	modScroller.render_string( "spinner with", xoff+70, yoff+45 );
-	modScroller.render_string( "first.", xoff+70, yoff+55 );
+	modScroller.render_string((char *) "--Order--", xoff+70, yoff+5 );
+	modScroller.render_string((char *) "Shows which", xoff+70, yoff+15 );
+	modScroller.render_string((char *) "color balls", xoff+70, yoff+ 25 );
+	modScroller.render_string((char *) "to fill the", xoff+70, yoff+35);
+	modScroller.render_string((char *) "spinner with", xoff+70, yoff+45 );
+	modScroller.render_string((char *) "first.", xoff+70, yoff+55 );
 	yoff += 70 ;
 	graphDriver->graph_draw( BMP_BACK_GAME, xoff, yoff );
 	graphDriver->graph_draw( BMP_NEXT_BASE, xoff, yoff );
 	graphDriver->graph_draw( BMP_GEM_C1, xoff + 24, yoff + 24 );
-	modScroller.render_string( "--Next Ball--", xoff+70, yoff+5 );
-	modScroller.render_string( "Shows what the", xoff+70, yoff+15 );
-	modScroller.render_string( "color of the", xoff+70, yoff+ 25 );
-	modScroller.render_string( "next ball will", xoff+70, yoff+35);
-	modScroller.render_string( "be.", xoff+70, yoff+45);
+	modScroller.render_string((char *) "--Next Ball--", xoff+70, yoff+5 );
+	modScroller.render_string((char *) "Shows what the", xoff+70, yoff+15 );
+	modScroller.render_string((char *) "color of the", xoff+70, yoff+ 25 );
+	modScroller.render_string((char *) "next ball will", xoff+70, yoff+35);
+	modScroller.render_string((char *) "be.", xoff+70, yoff+45);
 	yoff += 70 ;
 	graphDriver->graph_draw( BMP_BACK_GAME, xoff, yoff );
 	graphDriver->graph_draw( BMP_TIMER, xoff, yoff );
-	modScroller.render_string( "--Map Timer--", xoff+70, yoff+5 );
-	modScroller.render_string( "Counts down", xoff+70, yoff+15 );
-	modScroller.render_string( "the time left", xoff+70, yoff+ 25 );
-	modScroller.render_string( "to complete", xoff+70, yoff+35);
-	modScroller.render_string( "the map.", xoff+70, yoff+45);
+	modScroller.render_string((char *) "--Map Timer--", xoff+70, yoff+5 );
+	modScroller.render_string((char *) "Counts down", xoff+70, yoff+15 );
+	modScroller.render_string((char *) "the time left", xoff+70, yoff+ 25 );
+	modScroller.render_string((char *) "to complete", xoff+70, yoff+35);
+	modScroller.render_string((char *) "the map.", xoff+70, yoff+45);
 	xoff = 420;
 	yoff = 50 ;
 	graphDriver->graph_draw( BMP_BACK_GAME, xoff, yoff );
 	graphDriver->graph_draw( BMP_STARTTIMER_00, xoff + 7, yoff + 8 );
-	modScroller.render_string( "--Ball Timer--", xoff+70, yoff+5 );
-	modScroller.render_string( "Indicates how", xoff+70, yoff+15 );
-	modScroller.render_string( "much time you", xoff+70, yoff+ 25 );
-	modScroller.render_string( "have to get", xoff+70, yoff+ 35 );
-	modScroller.render_string( "the ball off the", xoff+70, yoff+45);
-	modScroller.render_string( "starting track.", xoff+70, yoff+55 );
+	modScroller.render_string((char *) "--Ball Timer--", xoff+70, yoff+5 );
+	modScroller.render_string((char *) "Indicates how", xoff+70, yoff+15 );
+	modScroller.render_string((char *) "much time you", xoff+70, yoff+ 25 );
+	modScroller.render_string((char *) "have to get", xoff+70, yoff+ 35 );
+	modScroller.render_string((char *) "the ball off the", xoff+70, yoff+45);
+	modScroller.render_string((char *) "starting track.", xoff+70, yoff+55 );
 	yoff += 70 ;
 	graphDriver->graph_draw( BMP_BACK_GAME, xoff, yoff );
 	graphDriver->graph_draw( BMP_BLOCK_BASE, xoff, yoff );
 	graphDriver->graph_draw( BMP_GEM_C1, xoff + 24, yoff + 24 );
-	modScroller.render_string( "--Blocker--", xoff+70, yoff+5 );
-	modScroller.render_string( "Only balls that", xoff+70, yoff+15 );
-	modScroller.render_string( "match the", xoff+70, yoff+ 25 );
-	modScroller.render_string( "blocker's color", xoff+70, yoff+35);
-	modScroller.render_string( "may pass.", xoff+70, yoff+45);
+	modScroller.render_string((char *) "--Blocker--", xoff+70, yoff+5 );
+	modScroller.render_string((char *) "Only balls that", xoff+70, yoff+15 );
+	modScroller.render_string((char *) "match the", xoff+70, yoff+ 25 );
+	modScroller.render_string((char *) "blocker's color", xoff+70, yoff+35);
+	modScroller.render_string((char *) "may pass.", xoff+70, yoff+45);
 	yoff += 70 ;
 	graphDriver->graph_draw( BMP_BACK_GAME, xoff, yoff );
 	graphDriver->graph_draw( BMP_PAINT_BASE, xoff, yoff );
 	graphDriver->graph_draw( BMP_GEM_C1, xoff + 24, yoff + 24 );
-	modScroller.render_string( "--Painter--", xoff+70, yoff+5 );
-	modScroller.render_string( "Changes the color", xoff+70, yoff+15 );
-	modScroller.render_string( "of the ball to", xoff+70, yoff+ 25 );
-	modScroller.render_string( "match", xoff+70, yoff+35);
+	modScroller.render_string((char *) "--Painter--", xoff+70, yoff+5 );
+	modScroller.render_string((char *) "Changes the color", xoff+70, yoff+15 );
+	modScroller.render_string((char *) "of the ball to", xoff+70, yoff+ 25 );
+	modScroller.render_string((char *) "match", xoff+70, yoff+35);
 	yoff += 70 ;
 	xoff = 10;
 	yoff = 265 ;
 	graphDriver->graph_draw( BMP_BACK_GAME, xoff, yoff );
 	graphDriver->graph_draw( BMP_NEXT_BASE, xoff, yoff );
 	graphDriver->graph_draw( BMP_ARROW_R, xoff + 23, yoff + 23 );
-	modScroller.render_string( "--Oneway--", xoff+70, yoff+5 );
-	modScroller.render_string( "Balls may only", xoff+70, yoff+15 );
-	modScroller.render_string( "travel in the", xoff+70, yoff+ 25 );
-	modScroller.render_string( "direction of the", xoff+70, yoff+35);
-	modScroller.render_string( "arrow.", xoff+70, yoff+45 );
+	modScroller.render_string((char *) "--Oneway--", xoff+70, yoff+5 );
+	modScroller.render_string((char *) "Balls may only", xoff+70, yoff+15 );
+	modScroller.render_string((char *) "travel in the", xoff+70, yoff+ 25 );
+	modScroller.render_string((char *) "direction of the", xoff+70, yoff+35);
+	modScroller.render_string((char *) "arrow.", xoff+70, yoff+45 );
 	xoff = 235;
 	yoff = 265 ;
 	graphDriver->graph_draw( BMP_BACK_GAME, xoff, yoff );
 	graphDriver->graph_draw( BMP_SPIN_0, xoff, yoff );
-	modScroller.render_string( "--Spinner--", xoff+70, yoff+5 );
-	modScroller.render_string( "Must be filled with balls of the", xoff+70, yoff+15 );
-	modScroller.render_string( "same color or following the order", xoff+70, yoff+ 25 );
-	modScroller.render_string( "and pattern tiles.  Right-click", xoff+70, yoff+35);
-	modScroller.render_string( "to spin.  Left-click on a ball to", xoff+70, yoff+45 );
-	modScroller.render_string( "eject it.", xoff+70, yoff+55 );
+	modScroller.render_string((char *) "--Spinner--", xoff+70, yoff+5 );
+	modScroller.render_string((char *) "Must be filled with balls of the", xoff+70, yoff+15 );
+	modScroller.render_string((char *) "same color or following the order", xoff+70, yoff+ 25 );
+	modScroller.render_string((char *) "and pattern tiles.  Right-click", xoff+70, yoff+35);
+	modScroller.render_string((char *) "to spin.  Left-click on a ball to", xoff+70, yoff+45 );
+	modScroller.render_string((char *) "eject it.", xoff+70, yoff+55 );
 
 	xoff = 230;
 	yoff = 340 ;
-	modScroller.render_string( "[ESC]   - Bring up the menu", xoff, yoff );
-	modScroller.render_string( "[LEFT]  - Play Previous MOD", xoff, yoff+10 );
-	modScroller.render_string( "[RIGHT] - Play Next MOD", xoff, yoff+20 );
+	modScroller.render_string((char *) "[ESC]   - Bring up the menu", xoff, yoff );
+	modScroller.render_string((char *) "[LEFT]  - Play Previous MOD", xoff, yoff+10 );
+	modScroller.render_string((char *) "[RIGHT] - Play Next MOD", xoff, yoff+20 );
 
 	yoff = 375;
-	modScroller.render_string_center( "The object of the game is to fill up the spinners on the", 0, PLAYWIDTH, yoff );
+	modScroller.render_string_center((char *) "The object of the game is to fill up the spinners on the", 0, PLAYWIDTH, yoff );
 	yoff += 10;
-	modScroller.render_string_center( "map with balls of the same color.  If there is a pattern", 0, PLAYWIDTH, yoff );
+	modScroller.render_string_center((char *) "map with balls of the same color.  If there is a pattern", 0, PLAYWIDTH, yoff );
 	yoff += 10;
-	modScroller.render_string_center( "indicator on the level, the spinners must match that", 0, PLAYWIDTH, yoff );
+	modScroller.render_string_center((char *) "indicator on the level, the spinners must match that", 0, PLAYWIDTH, yoff );
 	yoff += 10;
-	modScroller.render_string_center( "pattern instead.  If there is an order indicator", 0, PLAYWIDTH, yoff );
+	modScroller.render_string_center((char *) "pattern instead.  If there is an order indicator", 0, PLAYWIDTH, yoff );
 	yoff += 10;
-	modScroller.render_string_center( "then the spinners must be filled with balls matching", 0, PLAYWIDTH, yoff );
+	modScroller.render_string_center((char *) "then the spinners must be filled with balls matching", 0, PLAYWIDTH, yoff );
 	yoff += 10;
-	modScroller.render_string_center( "the colors in the order indicator until it is empty.", 0, PLAYWIDTH, yoff );
+	modScroller.render_string_center((char *) "the colors in the order indicator until it is empty.", 0, PLAYWIDTH, yoff );
 	yoff += 10;
-	modScroller.render_string_center( "", 0, PLAYWIDTH, yoff );
+	modScroller.render_string_center((char *) "", 0, PLAYWIDTH, yoff );
 
 }
 
@@ -2125,7 +2124,7 @@
 	} else {
 		if (!noModInfoSet)
 		{
-			modScroller.set_string( "NO MODULE INFO" );
+			modScroller.set_string((char *) "NO MODULE INFO" );
 			noModInfoSet = true;
 		}
 		modScroller.draw( );
