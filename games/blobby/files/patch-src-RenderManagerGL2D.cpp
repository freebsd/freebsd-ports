--- src/RenderManagerGL2D.cpp.orig	2011-11-10 17:25:30.977965807 +0100
+++ src/RenderManagerGL2D.cpp	2011-11-10 17:25:31.029970322 +0100
@@ -284,7 +284,8 @@
 		SDL_Rect r = {x, 0, fontSurface->w, fontSurface->h};
 		SDL_BlitSurface(fontSurface, 0, textbase, &r);
 		SDL_BlitSurface(highlight, 0, hltextbase, &r);
-		r = {sx, 0, fontSurface2->w, fontSurface2->h};
+		r.x = sx; r.y = 0;
+		r.w = fontSurface2->w; r.h = fontSurface2->h;
 		SDL_BlitSurface(fontSurface2, 0, smalltextbase, &r);
 		SDL_BlitSurface(highlight2, 0, hlsmalltextbase, &r);
 		//GLuint ballImage = loadTexture(sf, false);
