--- src/MainWindow.cs.orig	2008-10-18 07:54:25.000000000 -0300
+++ src/MainWindow.cs	2008-11-17 18:05:48.000000000 -0300
@@ -2700,8 +2700,10 @@
 		
 		case Preferences.MAIN_WINDOW_WIDTH:
 		case Preferences.MAIN_WINDOW_HEIGHT:
-			main_window.Resize(Preferences.Get<int> (Preferences.MAIN_WINDOW_WIDTH),
-					   Preferences.Get<int> (Preferences.MAIN_WINDOW_HEIGHT));
+			if (Preferences.Get<int> (Preferences.MAIN_WINDOW_WIDTH) > 0 &&
+						  Preferences.Get<int> (Preferences.MAIN_WINDOW_HEIGHT) > 0)
+				main_window.Resize(Preferences.Get<int> (Preferences.MAIN_WINDOW_WIDTH),
+						   Preferences.Get<int> (Preferences.MAIN_WINDOW_HEIGHT));
 
 			break;
 		
