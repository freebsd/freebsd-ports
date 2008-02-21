--- widget/keyboard.cpp.orig	Tue Nov 27 22:06:05 2007
+++ widget/keyboard.cpp	Tue Nov 27 22:07:15 2007
@@ -293,7 +293,8 @@
 		// Emit the help text of current key(s)
 		emit statusRefreshed(statusText);
     	// Call the paint event (refresh the keyboard)
-		repaint();
+		if (keyColoring || keyColoringStart)
+			repaint();
 	}
 }
 
