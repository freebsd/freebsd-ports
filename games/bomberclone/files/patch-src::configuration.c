--- src/configuration.c.orig	Fri May  9 06:36:13 2003
+++ src/configuration.c	Mon May 12 18:46:54 2003
@@ -48,7 +48,7 @@
 	gfx.random_tileset = 1;
     bman.fieldsize.x = 25;
     bman.fieldsize.y = 17;
-    sprintf (bman.datapath, "data");
+    sprintf (bman.datapath, "@@LOCALBASE@@/share/bomberclone");
     bman.fieldpath[0] = 0;
 	bman.random_map = 2;
 	init_map_tileset();
