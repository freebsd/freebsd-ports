--- src/rom.c.orig	2003-07-19 16:04:45 UTC
+++ src/rom.c
@@ -51,6 +51,9 @@
 Sint16 rom_type=UNKNOW_TYPE;
 Uint8 rom_gb_type=UNKNOW;
 
+char *rom_name;
+ROM_TIMER *rom_timer;
+
 int check_dir(char *dir_name) {
 #ifdef WIN32
   BOOL res;
