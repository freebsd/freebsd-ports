--- source/games/diverboy.c	Tue Sep 20 08:37:39 2005
+++ source/games/diverboy.c.new	Thu Nov 17 16:26:26 2005
@@ -138,6 +138,8 @@
 {
 	static int framecounter = 0;
 	UINT8* map;
+	UINT8 *source;
+	UINT8 *finish;
 
 	framecounter++;
 
@@ -147,8 +149,8 @@
 	MAP_PALETTE_MAPPED_NEW(0x0,16,map);
 	clear_game_screen(ReadLong(&map[0]));
 
-	UINT8 *source = RAM_SPRITE;
-	UINT8 *finish = source + 0x4000;
+	source = RAM_SPRITE;
+	finish = source + 0x4000;
 
 	while (source < finish)
 	{
