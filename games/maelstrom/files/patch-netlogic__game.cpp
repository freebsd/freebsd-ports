--- ./netlogic/game.cpp.orig	2001-07-23 04:24:03.000000000 +0200
+++ ./netlogic/game.cpp	2013-12-28 11:39:16.000000000 +0100
@@ -232,7 +232,7 @@
 
 			lastDisplayed = gDisplayed;
 			screen->FillRect(0, 0, SCREEN_WIDTH, 12, ourBlack);
-			sprintf(caption,
+			snprintf(caption, sizeof(caption),
 				"You are player %d --- displaying player %d",
 						gOurPlayer+1, gDisplayed+1);
 			DrawText(SPRITES_WIDTH, 11, caption, geneva,
@@ -357,7 +357,7 @@
 				/* -- Erase old and draw new score */
 				screen->FillRect(45, gStatusLine+1,
 					score_width, text_height, ourBlack);
-				sprintf(numbuf, "%d", Score);
+				snprintf(numbuf, sizeof(numbuf), "%d", Score);
 				score_width = DrawText(45, gStatusLine+11, 
 						numbuf, geneva, STYLE_BOLD,
 							0xFF, 0xFF, 0xFF);
@@ -380,7 +380,7 @@
 		if (lastWave != gWave) {
 			screen->FillRect(255, gStatusLine+1,
 					wave_width, text_height, ourBlack);
-			sprintf(numbuf, "%d", gWave);
+			snprintf(numbuf, sizeof(numbuf), "%d", gWave);
 			wave_width = DrawText(255, gStatusLine+11, 
 					numbuf, geneva, STYLE_BOLD,
 							0xFF, 0xFF, 0xFF);
@@ -391,7 +391,7 @@
 		if (lastLives != Lives) {
 			screen->FillRect(319, gStatusLine+1,
 					lives_width, text_height, ourBlack);
-			sprintf(numbuf, "%-3.1d", Lives);
+			snprintf(numbuf, sizeof(numbuf), "%-3.1d", Lives);
 			lives_width = DrawText(319, gStatusLine+11,
 					numbuf, geneva, STYLE_BOLD,
 							0xFF, 0xFF, 0xFF);
@@ -402,7 +402,7 @@
 		if (lastBonus != Bonus) {
 			screen->FillRect(384, gStatusLine+1,
 					bonus_width, text_height, ourBlack);
-			sprintf(numbuf, "%-7.1d", Bonus);
+			snprintf(numbuf, sizeof(numbuf), "%-7.1d", Bonus);
 			bonus_width = DrawText(384, gStatusLine+11,
 					numbuf, geneva, STYLE_BOLD,
 							0xFF, 0xFF, 0xFF);
@@ -414,7 +414,7 @@
 			if (lastFrags != Frags) {
 				screen->FillRect(fragoff, gStatusLine+1,
 					frags_width, text_height, ourBlack);
-				sprintf(numbuf, "%-3.1d", Frags);
+				snprintf(numbuf, sizeof(numbuf), "%-3.1d", Frags);
 				frags_width = DrawText(fragoff, gStatusLine+11,
 						numbuf, geneva, STYLE_BOLD,
 							0xFF, 0xFF, 0xFF);
@@ -747,10 +747,11 @@
 		for ( i=0; i<gNumPlayers; ++i ) {
 			char buffer[BUFSIZ], num1[12], num2[12];
 
-			sprintf(num1, "%7.1d", final[i].Score);
-			sprintf(num2, "%3.1d", final[i].Frags);
-			sprintf(buffer, "Player %d: %-.7s Points, %-.3s Frags",
-						final[i].Player, num1, num2);
+			snprintf(num1, sizeof(num1), "%7.1d", final[i].Score);
+			snprintf(num2, sizeof(num2), "%3.1d", final[i].Frags);
+			snprintf(buffer, sizeof(buffer),
+				 "Player %d: %-.7s Points, %-.3s Frags",
+				 final[i].Player, num1, num2);
 			DrawText(160, 380+i*newyork_height, buffer,
 				newyork, STYLE_NORM, 30000>>8, 30000>>8, 0xFF);
 		}
@@ -898,7 +899,7 @@
 	
 
 	/* -- Draw the wave completed message */
-	sprintf(numbuf, "Wave %d completed.", gWave);
+	snprintf(numbuf, sizeof(numbuf), "Wave %d completed.", gWave);
 	sw = fontserv->TextWidth(numbuf, geneva, STYLE_BOLD);
 	x = (SCREEN_WIDTH - sw) / 2;
 	DrawText(x,  150, numbuf, geneva, STYLE_BOLD, 0xFF, 0xFF, 0x00);
@@ -935,7 +936,7 @@
 		if (OurShip->GetBonusMult() != 1) {
 			SDL_Surface *sprite;
 
-			sprintf(numbuf, "%-5.1d", OurShip->GetBonus());
+			snprintf(numbuf, sizeof(numbuf), "%-5.1d", OurShip->GetBonus());
 			DrawText(x, 200, numbuf, geneva, STYLE_BOLD,
 							0xFF, 0xFF, 0xFF);
 			x += 75;
@@ -951,10 +952,10 @@
 	Delay(SOUND_DELAY);
 	sound->PlaySound(gFunk, 5);
 
-	sprintf(numbuf, "%-5.1d", OurShip->GetBonus());
+	snprintf(numbuf, sizeof(numbuf), "%-5.1d", OurShip->GetBonus());
 	bonus_width = DrawText(x, 200, numbuf, geneva, STYLE_BOLD,
 							0xFF, 0xFF, 0xFF);
-	sprintf(numbuf, "%-5.1d", OurShip->GetScore());
+	snprintf(numbuf, sizeof(numbuf), "%-5.1d", OurShip->GetScore());
 	score_width = DrawText(xt, 220, numbuf, geneva, STYLE_BOLD,
 							0xFF, 0xFF, 0xFF);
 	screen->Update();
@@ -997,12 +998,12 @@
 	
 			screen->FillRect(x, 200-text_height+2,
 					bonus_width, text_height, ourBlack);
-			sprintf(numbuf, "%-5.1d", OurShip->GetBonus());
+			snprintf(numbuf, sizeof(numbuf), "%-5.1d", OurShip->GetBonus());
 			bonus_width = DrawText(x, 200, numbuf,
 					geneva, STYLE_BOLD, 0xFF, 0xFF, 0xFF);
 			screen->FillRect(xt, 220-text_height+2,
 					score_width, text_height, ourBlack);
-			sprintf(numbuf, "%-5.1d", OurShip->GetScore());
+			snprintf(numbuf, sizeof(numbuf), "%-5.1d", OurShip->GetScore());
 			score_width = DrawText(xt, 220, numbuf,
 					geneva, STYLE_BOLD, 0xFF, 0xFF, 0xFF);
 
@@ -1015,7 +1016,7 @@
 	HandleEvents(10);
 
 	/* -- Draw the "next wave" message */
-	sprintf(numbuf, "Prepare for Wave %d...", gWave+1);
+	snprintf(numbuf, sizeof(numbuf), "Prepare for Wave %d...", gWave+1);
 	sw = fontserv->TextWidth(numbuf, geneva, STYLE_BOLD);
 	x = (SCREEN_WIDTH - sw)/2;
 	DrawText(x, 259, numbuf, geneva, STYLE_BOLD, 0xFF, 0xFF, 0x00);
