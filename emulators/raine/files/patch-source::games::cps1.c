--- source/games/cps1.c.orig	Mon Jan 17 10:56:50 2005
+++ source/games/cps1.c	Mon Jan 17 11:35:07 2005
@@ -1437,11 +1437,13 @@

 void load_cps2() {
   UINT16 *rom = (UINT16*)load_region[REGION_ROM1];
-  xor = (UINT16*)load_region[REGION_USER1];
+  UINT8 *tmp;
+  int i, size_code, size_user1;
 /*   int size = get_region_size(REGION_USER1)/2,i,size_code; */
-  int size_code = get_region_size(REGION_ROM1),i;
-  int size_user1 = get_region_size(REGION_USER1);
-  UINT8 *tmp = AllocateMem(size_user1);
+  xor = (UINT16*)load_region[REGION_USER1];
+  size_code = get_region_size(REGION_ROM1);
+  size_user1 = get_region_size(REGION_USER1);
+  tmp = AllocateMem(size_user1);
   if (!init_tilequeue()) return;
   init_pbitmap();

