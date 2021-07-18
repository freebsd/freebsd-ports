Fix compatibility with C++17, which is required to build with boost 1.76

--- src/system/utility/ImageUtility.cpp.orig	2016-01-04 20:15:21 UTC
+++ src/system/utility/ImageUtility.cpp
@@ -23,8 +23,8 @@ SDL_Surface *ImageUtility::loadImage(boost::filesystem
 SDL_Surface *ImageUtility::createImage(TTF_Font *font, char fgR, char fgG,
 		char fgB, char fgA, char bgR, char bgG, char bgB, char bgA,
 		std::string text, FontRenderingFlag quality) {
-	SDL_Color tmpfontcolor = { fgR, fgG, fgB, fgA };
-	SDL_Color tmpfontbgcolor = { bgR, bgG, bgB, bgA };
+	SDL_Color tmpfontcolor = { (Uint8)fgR, (Uint8)fgG, (Uint8)fgB, (Uint8)fgA };
+	SDL_Color tmpfontbgcolor = { (Uint8)bgR, (Uint8)bgG, (Uint8)bgB, (Uint8)bgA };
 	SDL_Surface *resulting_text = NULL;
 
 	if (quality == solid)
