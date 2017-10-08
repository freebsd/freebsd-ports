SDL_FreeSurface deallocates surface->map even if the surface is not yet freed
https://bugzilla.libsdl.org/show_bug.cgi?id=3852

Memory leak in SDL_FreeSurface (after bug 3852 fix)
https://bugzilla.libsdl.org/show_bug.cgi?id=3855

--- src/video/SDL_surface.c.orig	2017-09-22 18:51:01 UTC
+++ src/video/SDL_surface.c
@@ -1198,10 +1198,8 @@ SDL_FreeSurface(SDL_Surface * surface)
     if (surface->flags & SDL_DONTFREE) {
         return;
     }
-    if (surface->map != NULL) {
-        SDL_FreeBlitMap(surface->map);
-        surface->map = NULL;
-    }
+    SDL_InvalidateMap(surface->map);
+
     if (--surface->refcount > 0) {
         return;
     }
@@ -1219,6 +1217,9 @@ SDL_FreeSurface(SDL_Surface * surface)
     if (!(surface->flags & SDL_PREALLOC)) {
         SDL_free(surface->pixels);
     }
+    if (surface->map) {
+        SDL_FreeBlitMap(surface->map);
+    }
     SDL_free(surface);
 }
 
