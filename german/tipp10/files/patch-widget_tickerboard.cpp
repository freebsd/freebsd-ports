--- widget/tickerboard.cpp.orig	2013-10-02 09:55:42.000000000 +0000
+++ widget/tickerboard.cpp
@@ -97,7 +97,7 @@ void TickerBoard::startTicker(bool wasPa
 
 		if (tickerSpeed == 50) {
 			scrollOffset = 290;
-			scroll(-290, 0, QRect::QRect(10, 15, 590, 35)); //contentsRect());
+			scroll(-290, 0, QRect(10, 15, 590, 35)); //contentsRect());
 		}
 
 		startFlag = true;
@@ -153,7 +153,7 @@ void TickerBoard::changeChar() {
 			scrollOffset = 0;
 		} else {
 			scrollOffset = 290;
-			scroll(-290, 0, QRect::QRect(10, 15, 590, 35)); //contentsRect());
+			scroll(-290, 0, QRect(10, 15, 590, 35)); //contentsRect());
 		}
 		splitLesson();
 	}
@@ -242,7 +242,7 @@ void TickerBoard::progress() {
 
 				// Move ticker 1 pixel to left
 				scrollOffset++;
-				scroll(-1, 0, QRect::QRect(10, 15, 590, 35)); //contentsRect());
+				scroll(-1, 0, QRect(10, 15, 590, 35)); //contentsRect());
 
 				if ((lessonOffset - scrollOffset) <= 30) {
 					setSpeed(tickerSpeed);
@@ -265,14 +265,14 @@ void TickerBoard::progress() {
 			// 160 pixels overage (because the user must see at least the next word)
 			if ((lessonOffset - scrollOffset) > 200) {
 				scrollOffset += (lessonOffset - scrollOffset) - 200;
-				scroll(-((lessonOffset - scrollOffset) - 200), 0, QRect::QRect(10, 15, 590, 35)); //contentsRect());
+				scroll(-((lessonOffset - scrollOffset) - 200), 0, QRect(10, 15, 590, 35)); //contentsRect());
 			}
 		} else {
 			// If the user types faster than the ticker, move ticker faster after
 			// 160 pixels overage (because the user must see at least the next word)
 			if ((lessonOffset - scrollOffset) > 280) {
 				scrollOffset += 570;
-				scroll(-570, 0, QRect::QRect(10, 15, 590, 35)); //contentsRect());
+				scroll(-570, 0, QRect(10, 15, 590, 35)); //contentsRect());
 			}
 
 		}
