--- libretro/retro_events.h.orig	2020-04-17 23:23:41 UTC
+++ libretro/retro_events.h
@@ -154,7 +154,7 @@ typedef struct {
 #define JOY_EVENT_ID_Y 1
 
 void ev_joysticks();
-bool (*ev_events)(void);
+extern bool (*ev_events)(void);
 void ev_combo_set(unsigned btn);
 void ev_init();
 
