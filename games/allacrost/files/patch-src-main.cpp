--- src/main.cpp.orig	Mon Sep 11 00:31:22 2006
+++ src/main.cpp	Wed Oct  4 03:11:59 2006
@@ -84,6 +84,7 @@
 
 // Every great game begins with a single function :)
 int32 main(int32 argc, char *argv[]) {
+	chdir(DATADIR);
 	// When the program exits, first the QuitAllacrost() function, followed by SDL_Quit()
 	atexit(SDL_Quit);
 	atexit(QuitAllacrost);
