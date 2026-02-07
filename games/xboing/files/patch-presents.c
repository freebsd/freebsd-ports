--- presents.c.orig	1996-11-22 01:28:46 UTC
+++ presents.c
@@ -287,7 +287,7 @@ void DoPresentFlag(display, window)
 	}
 #endif
 
-	SetPresentWait(PRESENT_TEXT1, frame + 800);
+	SetPresentWait(PRESENT_TEXT1, frame + 200);
 }
 
 #if NeedFunctionPrototypes
@@ -309,7 +309,7 @@ static void DoText1(display, window)
 	RenderShape(display, window, justin, justinM,
 		x, y, 285, 44, True);
 
-	SetPresentWait(PRESENT_TEXT2, frame + 300);
+	SetPresentWait(PRESENT_TEXT2, frame + 100);
 }
 
 #if NeedFunctionPrototypes
@@ -331,7 +331,7 @@ static void DoText2(display, window)
 	RenderShape(display, window, kibell, kibellM,
 		x, y, 260, 40, True);
 
-	SetPresentWait(PRESENT_TEXT3, frame + 500);
+	SetPresentWait(PRESENT_TEXT3, frame + 200);
 }
 
 #if NeedFunctionPrototypes
@@ -355,7 +355,7 @@ static void DoText3(display, window)
 	RenderShape(display, window, presents, presentsM,
 		x, y, 410, 44, True);
 
-	SetPresentWait(PRESENT_TEXT_CLEAR, frame + 750);
+	SetPresentWait(PRESENT_TEXT_CLEAR, frame + 250);
 }
 
 #if NeedFunctionPrototypes
@@ -375,7 +375,7 @@ static void DoTextClear(display, window)
 
 	FadeAwayArea(display, window, x, y, 410, 44);
 
-	SetPresentWait(PRESENT_LETTERS, frame + 10);
+	SetPresentWait(PRESENT_LETTERS, frame + 5);
 }
 
 /* The distances for the gap inbetwen blocks */
@@ -404,7 +404,7 @@ static void DoLetters(display, window)
 		DrawLetter(display, window, i, x, y);
 		x += 10 + dists[i];
 
-		SetPresentWait(PRESENT_LETTERS, frame + 300);
+		SetPresentWait(PRESENT_LETTERS, frame + 100);
 	}
 	else
 	{
@@ -416,7 +416,7 @@ static void DoLetters(display, window)
 		x += dists[3];
 		DrawLetter(display, window, 3, x, y);
 
-		SetPresentWait(PRESENT_SHINE, frame + 200);
+		SetPresentWait(PRESENT_SHINE, frame + 100);
 	}
 
 	i++;
@@ -463,7 +463,7 @@ static void DoSparkle(display, window)
         if (in == 11)
         {
             XCopyArea(display, store, window, gc, 0, 0, 20, 20, x, y);
-			SetPresentWait(PRESENT_SPECIAL_TEXT1, frame + 500);
+			SetPresentWait(PRESENT_SPECIAL_TEXT1, frame + 100);
         }
     }
 }
@@ -499,7 +499,7 @@ static void DoSpecialText1(display, window)
 		len = strlen(wisdom);
 		x = ((PLAY_WIDTH + MAIN_WIDTH) / 2) - 
 			(XTextWidth(dataFont, wisdom, len) / 2);
-		nextFrame = frame + 10;
+		nextFrame = frame + 5;
 		first = False;
 	}
 
@@ -508,11 +508,11 @@ static void DoSpecialText1(display, window)
 		if (noSound == False) playSoundFile("key", 60);
 		DrawText(display, window, x, y, dataFont, red, wisdom, i);
 
-		nextFrame = frame + 30;
+		nextFrame = frame + 15;
 
 		i++;
 		if (i > len)
-			SetPresentWait(PRESENT_SPECIAL_TEXT2, frame + 700);
+			SetPresentWait(PRESENT_SPECIAL_TEXT2, frame + 150);
 	}
 }
 
@@ -542,7 +542,7 @@ static void DoSpecialText2(display, window)
 		len = strlen(wisdom2);
 		x = ((PLAY_WIDTH + MAIN_WIDTH) / 2) - 
 			(XTextWidth(dataFont, wisdom2, len) / 2);
-		nextFrame = frame + 10;
+		nextFrame = frame + 5;
 		first = False;
 	}
 
@@ -551,11 +551,11 @@ static void DoSpecialText2(display, window)
 		if (noSound == False) playSoundFile("key", 60);
 		DrawText(display, window, x, y, dataFont, red, wisdom2, i);
 
-		nextFrame = frame + 30;
+		nextFrame = frame + 15;
 
 		i++;
 		if (i > len)
-			SetPresentWait(PRESENT_SPECIAL_TEXT3, frame + 700);
+			SetPresentWait(PRESENT_SPECIAL_TEXT3, frame + 150);
 	}
 }
 
@@ -584,7 +584,7 @@ static void DoSpecialText3(display, window)
 		len = strlen(wisdom3);
 		x = ((PLAY_WIDTH + MAIN_WIDTH) / 2) - 
 			(XTextWidth(dataFont, wisdom3, len) / 2);
-		nextFrame = frame + 10;
+		nextFrame = frame + 5;
 		first = False;
 	}
 
@@ -593,11 +593,11 @@ static void DoSpecialText3(display, window)
 		if (noSound == False) playSoundFile("key", 60);
 		DrawText(display, window, x, y, dataFont, red, wisdom3, i);
 
-		nextFrame = frame + 30;
+		nextFrame = frame + 15;
 
 		i++;
 		if (i > len)
-			SetPresentWait(PRESENT_CLEAR, frame + 800);
+			SetPresentWait(PRESENT_CLEAR, frame + 200);
 	}
 }
 
@@ -642,7 +642,7 @@ static void DoClear(display, window)
 		yb -= 10;
 
 		if (yt > ((PLAY_HEIGHT + MAIN_HEIGHT) / 2))
-			SetPresentWait(PRESENT_FINISH, frame + 20);
+			SetPresentWait(PRESENT_FINISH, frame + 10);
 
 		nextFrame = frame + 20;
 	}
