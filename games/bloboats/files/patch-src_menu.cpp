--- src/menu.cpp.orig	2017-02-03 12:18:46 UTC
+++ src/menu.cpp
@@ -1567,7 +1567,8 @@ void menu::resolution() {
 	// Get resolutions
 	vector<Resolution> resolutions;
 	SDL_Rect** modes = SDL_ListModes(NULL, SDL_FULLSCREEN|SDL_HWSURFACE|SDL_OPENGL);
-	if(modes > 0) {
+	// if(modes > 0) {
+	if(modes != '\0') {
 		Uint32 bpp = SDL_GetVideoInfo()->vfmt->BitsPerPixel;
 		for(int i=0; modes[i] && i < 10; ++i) {
 			Resolution resolution;
