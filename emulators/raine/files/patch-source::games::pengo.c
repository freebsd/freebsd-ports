--- source/games/pengo.c.orig	Mon Jan 17 10:46:35 2005
+++ source/games/pengo.c	Mon Jan 17 10:47:35 2005
@@ -444,11 +444,11 @@
 }

 static void load_pengo() {
-  RAMSize = 0x1032+0x8000;
   UINT8 *color_prom = load_region[REGION_PROMS];
   UINT8 *decode1,*decode2,palette[32*2];
   UINT32 dest_size;
   int i;
+  RAMSize = 0x1032+0x8000;

   if(!(RAM=AllocateMem(RAMSize))) return;

@@ -1536,10 +1536,10 @@
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
