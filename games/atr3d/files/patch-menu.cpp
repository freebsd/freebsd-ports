--- menu.cpp.orig	2008-02-19 19:29:51.000000000 +0100
+++ menu.cpp	2008-02-19 19:30:51.000000000 +0100
@@ -194,8 +194,8 @@
 
   ClearScreen();
   DrawText(ScreenWidth/2-200, ScreenHeight/2+50,
-	   "Congratulations, you've made a high score", &Blue, 1);
-  pos=DrawText(ScreenWidth/2-200, ScreenHeight/2, "Enter Name", &Blue, 1);
+	   (char *)"Congratulations, you've made a high score", &Blue, 1);
+  pos=DrawText(ScreenWidth/2-200, ScreenHeight/2, (char *)"Enter Name", &Blue, 1);
   DrawRect(pos+17, ScreenHeight/2-2, pos+17, ScreenHeight/2+20,
 	   pos+300, ScreenHeight/2+20, pos+300, ScreenHeight/2-2, &DarkGray);
   pos=DrawText(pos+20, ScreenHeight/2, TextValue, &Red, 1);
@@ -319,8 +319,8 @@
   int NumScoresDisplayed;
   struct Color *TextColor;
 
-  DrawText(20, ScreenHeight-50, "Name", &Blue, 1);
-  DrawText(ScreenWidth/2, ScreenHeight-50, "Score", &Blue, 1);
+  DrawText(20, ScreenHeight-50, (char *)"Name", &Blue, 1);
+  DrawText(ScreenWidth/2, ScreenHeight-50, (char *)"Score", &Blue, 1);
 
   NumScoresDisplayed=(ScreenHeight-(150+25*NumScoreMenuItems))/25;
   if (NumScoresDisplayed > NUM_HIGHSCORES) {
