--- hedgewars/uMisc.pas.orig	2025-07-22 17:12:55 UTC
+++ hedgewars/uMisc.pas
@@ -344,7 +344,9 @@
 var convertedSurf: PSDL_Surface;
 begin
     doSurfaceConversion:= tmpsurf;
-    if ((tmpsurf^.format^.bitsperpixel = 32) and (tmpsurf^.format^.rshift > tmpsurf^.format^.bshift)) or
+    // the engine expects pixels stored as R, G, B, A bytes in memory
+    // (RMask, RShift etc. in SDLh.pas), so check that red is where we expect it
+    if ((tmpsurf^.format^.bitsperpixel = 32) and (tmpsurf^.format^.rshift <> RShift)) or
        (tmpsurf^.format^.bitsperpixel = 24) then
     begin
         convertedSurf:= SDL_ConvertSurface(tmpsurf, conversionFormat, SDL_SWSURFACE);
@@ -370,8 +372,14 @@
 
 procedure initModule;
 const SDL_PIXELFORMAT_ABGR8888 = (1 shl 28) or (6 shl 24) or (7 shl 20) or (6 shl 16) or (32 shl 8) or 4;
+      SDL_PIXELFORMAT_RGBA8888 = (1 shl 28) or (6 shl 24) or (4 shl 20) or (6 shl 16) or (32 shl 8) or 4;
 begin
+    // R, G, B, A bytes in memory (SDL_PIXELFORMAT_RGBA32) on both endians
+{$IFDEF ENDIAN_LITTLE}
     conversionFormat:= SDL_AllocFormat(SDL_PIXELFORMAT_ABGR8888);
+{$ELSE}
+    conversionFormat:= SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
+{$ENDIF}
 end;
 
 procedure freeModule;
