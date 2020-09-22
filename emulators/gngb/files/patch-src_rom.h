--- src/rom.h.orig	2003-04-03 13:27:29 UTC
+++ src/rom.h
@@ -37,7 +37,7 @@
 #define SRAM           0x200
 #define HUC1           0x400
 
-char *rom_name;
+extern char *rom_name;
 extern Sint16 rom_type;
 
 //  rom_gb_suport
@@ -52,7 +52,7 @@ typedef struct {
   Uint8 regl[5];   // register locked
 }ROM_TIMER; // MBC3
 
-ROM_TIMER *rom_timer;
+extern ROM_TIMER *rom_timer;
 
 int open_rom(char *filename);
 
