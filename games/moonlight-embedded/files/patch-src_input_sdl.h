--- src/input/sdl.h.orig	2023-10-11 15:50:11 UTC
+++ src/input/sdl.h
@@ -105,3 +105,5 @@ void sdlinput_rumble(unsigned short controller_id, uns
 void sdlinput_rumble_triggers(unsigned short controller_id, unsigned short left_trigger, unsigned short right_trigger);
 void sdlinput_set_motion_event_state(unsigned short controller_id, unsigned char motion_type, unsigned short report_rate_hz);
 void sdlinput_set_controller_led(unsigned short controller_id, unsigned char r, unsigned char g, unsigned char b);
+void x11_sdl_init(char* mappings);
+void x11_sdl_stop();
