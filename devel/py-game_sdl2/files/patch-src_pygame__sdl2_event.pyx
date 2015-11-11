commit 1359d51
Author: Tom Rothamel <tom@rothamel.us>
Date:   Tue Nov 3 09:01:52 2015 -0500

    Allow event types to be longs.
    
    Fixes renpy/renpy#778.
---
 src/pygame_sdl2/event.pyx | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

diff --git src/pygame_sdl2/event.pyx src/pygame_sdl2/event.pyx
index 209fb83..22da508 100644
--- src/pygame_sdl2/event.pyx
+++ src/pygame_sdl2/event.pyx
@@ -416,7 +416,7 @@ def set_blocked(t=None):
     if t == None:
         for et in event_names.keys():
             SDL_EventState(et, SDL_ENABLE)
-    elif type(t) == int:
+    elif isinstance(t, (int, long)):
         SDL_EventState(t, SDL_IGNORE)
     else:
         for et in t:
@@ -426,7 +426,7 @@ def set_allowed(t=None):
     if t == None:
         for et in event_names.keys():
             SDL_EventState(et, SDL_IGNORE)
-    elif type(t) == int:
+    elif isinstance(t, (int, long)):
         SDL_EventState(t, SDL_ENABLE)
     else:
         for et in t:
