--- amarok/src/vis/libvisual/libvisual.cpp.orig	Sun Nov 28 16:51:39 2004
+++ amarok/src/vis/libvisual/libvisual.cpp	Sun Nov 28 16:52:56 2004
@@ -267,11 +267,11 @@
                 break;
 
             case SDL_MOUSEBUTTONDOWN:
-                visual_event_queue_add_mousebutton (vevent, event.button.button, VISUAL_MOUSE_DOWN);
+                visual_event_queue_add_mousebutton (vevent, event.button.button, VISUAL_MOUSE_DOWN, 0, 0);
                 break;
 
             case SDL_MOUSEBUTTONUP:
-                visual_event_queue_add_mousebutton (vevent, event.button.button, VISUAL_MOUSE_UP);
+                visual_event_queue_add_mousebutton (vevent, event.button.button, VISUAL_MOUSE_UP, 0, 0);
                 break;
 
             case SDL_QUIT:
