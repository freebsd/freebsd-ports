--- main.cpp.orig	Tue Jul 27 17:58:18 2004
+++ main.cpp	Tue Jul 27 17:58:45 2004
@@ -65,7 +65,7 @@
 
 // console
 int histLine;											// commands history scrolling value
-Var consoleKey("consoleKey", 167, VF_PERSISTENT);		// key used for console opening/closing
+Var consoleKey("consoleKey", '`', VF_PERSISTENT);		// key used for console opening/closing
 int tabmode = 1;										// console tabulation mode
 
 // window
