--- src/wlapplication.cc.orig	2011-04-15 22:40:26.000000000 +0400
+++ src/wlapplication.cc	2011-05-25 08:48:45.000000000 +0400
@@ -963,12 +963,12 @@
 	int result = -1;
 
 	//add default video mode
-#ifdef linux
-	videomode.push_back("x11");
-#elif WIN32
+#if defined WIN32
 	videomode.push_back("windib");
-#elif __APPLE__
+#elif defined __APPLE__
 	videomode.push_back("Quartz");
+#else
+	videomode.push_back("x11");
 #endif
 	//if a video mode is given on the command line, add that one first
 	const char * videodrv;
