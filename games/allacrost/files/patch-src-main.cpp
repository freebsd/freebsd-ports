--- src/main.cpp.orig	Thu Jun  7 00:18:13 2007
+++ src/main.cpp	Thu Jun  7 01:18:11 2007
@@ -96,6 +96,7 @@
 ***
 **/
 bool InitializeEngine() {
+	chdir(DATADIR);
 	// Initialize SDL. The video, audio, and joystick subsystems are initialized elsewhere.
 	if (SDL_Init(SDL_INIT_TIMER) != 0) {
 		cerr << "MAIN ERROR: Unable to initialize SDL: " << SDL_GetError() << endl;
