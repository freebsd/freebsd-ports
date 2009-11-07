--- src/program.cpp.orig	2009-11-05 01:13:34.000000000 +0300
+++ src/program.cpp	2009-11-07 03:32:21.000000000 +0300
@@ -1302,16 +1302,20 @@
 
 void drawWindows() {
 	if (!windows.empty()) {
-		std::map<std::string, Window*>::const_iterator win;
+		std::map<std::string, Window*>::iterator win, victim;
 		for (win = windows.begin(); win != windows.end(); ++win) {
 			Window* w = win->second;
 			w->draw();
 			w->process(input);
 		}
-		for (win = windows.begin(); win != windows.end(); ++win) {
-			Window* w = win->second;
-			if (w->CloseFlag)
-				windows.erase(win->first);
+		win = windows.begin();
+		while (win != windows.end()) {
+			if (win->second->CloseFlag) {
+				victim = win++;
+				windows.erase(victim);
+			} else {
+				win++;
+			}
 		}
 	}
 }
