--- ./main.cpp.orig	2002-10-20 04:53:32.000000000 +0200
+++ ./main.cpp	2013-12-28 11:39:16.000000000 +0100
@@ -445,7 +445,7 @@
 		DrawText(xOff+309-7, yOff+240-6, text, geneva, STYLE_BOLD,
 							0x00, 0x00, 0x00);
 	}
-	sprintf(text, "%d", gSoundLevel);
+	snprintf(text, sizeof(text), "%d", gSoundLevel);
 	DrawText(xOff+309-7, yOff+240-6, text, geneva, STYLE_BOLD,
 						30000>>8, 30000>>8, 0xFF);
 	screen->Update();
@@ -547,11 +547,11 @@
 		}
 		DrawText(xOff+5, botDiv+42+(index*18), hScores[index].name,
 						font, STYLE_BOLD, R, G, B);
-		sprintf(buffer, "%u", hScores[index].score);
+		snprintf(buffer, sizeof(buffer), "%u", hScores[index].score);
 		sw = fontserv->TextWidth(buffer, font, STYLE_BOLD);
 		DrawText(sRt-sw, botDiv+42+(index*18), buffer, 
 						font, STYLE_BOLD, R, G, B);
-		sprintf(buffer, "%u", hScores[index].wave);
+		snprintf(buffer, sizeof(buffer), "%u", hScores[index].wave);
 		sw = fontserv->TextWidth(buffer, font, STYLE_BOLD);
 		DrawText(wRt-sw, botDiv+42+(index*18), buffer, 
 						font, STYLE_BOLD, R, G, B);
@@ -560,7 +560,7 @@
 
 	DrawText(xOff+5, botDiv+46+(10*18)+3, "Last Score: ", 
 					bigfont, STYLE_NORM, 0xFF, 0xFF, 0xFF);
-	sprintf(buffer, "%d", GetScore());
+	snprintf(buffer, sizeof(buffer), "%d", GetScore());
 	sw = fontserv->TextWidth("Last Score: ", bigfont, STYLE_NORM);
 	DrawText(xOff+5+sw, botDiv+46+(index*18)+3, buffer, 
 					bigfont, STYLE_NORM, 0xFF, 0xFF, 0xFF);
