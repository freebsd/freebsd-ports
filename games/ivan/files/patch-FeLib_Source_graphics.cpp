--- FeLib/Source/graphics.cpp.orig	2021-12-24 11:26:31 UTC
+++ FeLib/Source/graphics.cpp
@@ -264,11 +264,10 @@
 #endif
 }
 
-#if SDL_BYTEORDER == SDL_BIG_ENDIAN
+#if SDL_MAJOR_VERSION == 1 && SDL_BYTEORDER == SDL_BIG_ENDIAN
 
 void graphics::BlitDBToScreen()
 {
-#if SDL_MAJOR_VERSION == 1
   SDL_LockSurface(TempSurface);
   packcol16* SrcPtr = DoubleBuffer->GetImage()[0];
   packcol16* DestPtr = static_cast<packcol16*>(TempSurface->pixels);
@@ -283,9 +282,6 @@
   SDL_BlitSurface(S, NULL, Screen, NULL);
   SDL_FreeSurface(S);
   SDL_UpdateRect(Screen, 0, 0, Res.X, Res.Y);
-#else
-  SDL_UpdateTexture(sdlTexture, NULL, myPixels, 640 * sizeof (Uint32));
-#endif
 }
 
 #else
