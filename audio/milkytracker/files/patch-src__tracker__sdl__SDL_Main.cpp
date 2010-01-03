--- ./src/tracker/sdl/SDL_Main.cpp.orig	2010-01-03 19:15:39.000000000 +0100
+++ ./src/tracker/sdl/SDL_Main.cpp	2010-01-03 19:15:53.000000000 +0100
@@ -751,8 +751,8 @@
 		case SDLUserEventLMouseRepeat:
 		{
 			PPPoint p;
-			p.x = (pp_int32)event.data1;
-			p.y = (pp_int32)event.data2;
+			p.x = reinterpret_cast<intptr_t> (event.data1);
+			p.y = reinterpret_cast<intptr_t> (event.data2);
 			PPEvent myEvent(eLMouseRepeat, &p, sizeof(PPPoint));		
 			RaiseEventSerialized(&myEvent);
 			break;
@@ -761,8 +761,8 @@
 		case SDLUserEventRMouseRepeat:
 		{
 			PPPoint p;
-			p.x = (pp_int32)event.data1;
-			p.y = (pp_int32)event.data2;
+			p.x = reinterpret_cast<intptr_t> (event.data1);
+			p.y = reinterpret_cast<intptr_t> (event.data2);
 			PPEvent myEvent(eRMouseRepeat, &p, sizeof(PPPoint));		
 			RaiseEventSerialized(&myEvent);
 			break;
@@ -770,8 +770,8 @@
 
 		case SDLUserEventMidiKeyDown:
 		{
-			pp_int32 note = (pp_int32)event.data1;
-			pp_int32 volume = (pp_int32)event.data2;
+			pp_int32 note = reinterpret_cast<intptr_t> (event.data1);
+			pp_int32 volume = reinterpret_cast<intptr_t> (event.data2);
 			globalMutex->lock();
 			myTracker->sendNoteDown(note, volume);
 			globalMutex->unlock();
@@ -780,7 +780,7 @@
 
 		case SDLUserEventMidiKeyUp:
 		{
-			pp_int32 note = (pp_int32)event.data1;
+			pp_int32 note = reinterpret_cast<intptr_t> (event.data1);
 			globalMutex->lock();
 			myTracker->sendNoteUp(note);
 			globalMutex->unlock();
