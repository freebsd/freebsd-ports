--- source/games/pengo.c.orig	Sat Sep 17 19:16:59 2005
+++ source/games/pengo.c	Thu Nov 17 13:07:59 2005
@@ -446,11 +446,12 @@
 static int tile_cache_init;
 
 static void load_pengo() {
-  RAMSize = 0x1032+0x8000;
   UINT8 *color_prom = load_region[REGION_PROMS];
   UINT8 palette[32*2];
   int i;
 
+  RAMSize = 0x1032+0x8000;
+
   if(!(RAM=AllocateMem(RAMSize))) return;
 
   if (!strcmp(current_game->main_name,"pengo")) {// normal
@@ -1498,10 +1499,10 @@
 {
   // quite different from pengo for the init : no encoding, different memory map,
   // different palette...
-  RAMSize = 0x103a;
   UINT8 *color_prom = load_region[REGION_PROMS];
   UINT8 palette[32*2];
   int i;
+  RAMSize = 0x103a;
 
   if (!strcmp(current_game->main_name,"pacplus")) {
     for (i = 0; i < 0x4000; i++)
