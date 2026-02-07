--- src/game/cMainMenu.cpp.orig	2004-02-21 15:48:50.000000000 +0300
+++ src/game/cMainMenu.cpp	2013-10-19 04:20:28.484773573 +0400
@@ -399,7 +399,7 @@
 	
 	string &text = mDemoStrings[mCurrentString];
 	
-	static unsigned int i = 0;
+	static int i = 0;
 	if ( mLastLetter + 100 < now )
 	{
 		i++;
