--- src/common/font.cpp.orig	2018-11-05 15:29:33 UTC
+++ src/common/font.cpp
@@ -200,8 +200,8 @@ int Font::Write( const char *str, Surfac
   SDL_Color scol = { col.r, col.g, col.b };
   SDL_Surface *s = TTF_RenderUTF8_Blended( f, str, scol );
   if ( s ) {
-    SDL_Rect src = { 0, 0, s->w, s->h };
-    SDL_Rect dst = { x, y, s->w, s->h };
+    SDL_Rect src = { 0, 0, static_cast<Uint16>(s->w), static_cast<Uint16>(s->h) };
+    SDL_Rect dst = { x, y, static_cast<Uint16>(s->w), static_cast<Uint16>(s->h) };
     SDL_BlitSurface( s, &src, dest->s_surface, &dst );
     SDL_FreeSurface( s );
     return src.w;
