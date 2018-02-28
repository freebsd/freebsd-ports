--- src/tracker/sdl/SDL_Main.cpp.orig	2018-02-24 17:43:23 UTC
+++ src/tracker/sdl/SDL_Main.cpp
@@ -609,7 +609,7 @@ void translateKeyDownEvent(const SDL_Eve
 	printf ("DEBUG: Key pressed: VK: %d, SC: %d, Scancode: %d\n", toVK(keysym), toSC(keysym), keysym.sym);
 #endif
 
-	pp_uint16 chr[3] = {toVK(keysym), toSC(keysym), keysym.sym};
+	pp_uint16 chr[3] = {toVK(keysym), toSC(keysym), static_cast<pp_uint16> (keysym.sym)};
 
 	PPEvent myEvent(eKeyDown, &chr, sizeof(chr));
 	RaiseEventSerialized(&myEvent);
@@ -621,7 +621,7 @@ void translateKeyUpEvent(const SDL_Event
 
 	preTranslateKey(keysym);
 
-	pp_uint16 chr[3] = {toVK(keysym), toSC(keysym), keysym.sym};
+	pp_uint16 chr[3] = {toVK(keysym), toSC(keysym), static_cast<pp_uint16> (keysym.sym)};
 
 	PPEvent myEvent(eKeyUp, &chr, sizeof(chr));
 	RaiseEventSerialized(&myEvent);
