--- libretro/retro_events.c.orig	2021-02-19 01:54:05 UTC
+++ libretro/retro_events.c
@@ -56,6 +56,8 @@ const uint8_t bit_values[8] = {0x01, 0x02, 0x04, 0x08,
 #define MAX_BUTTONS 14
 #define MAX_PADCFG 4
 
+bool (*ev_events)(void);
+
 static uint8_t keyboard_translation[MAX_KEYSYMS];
 unsigned int last_input[PORTS_NUMBER] = {0,0};
 uint32_t padnum = 0;
