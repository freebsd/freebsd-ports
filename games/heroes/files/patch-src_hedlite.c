--- src/hedlite.c.orig	2002-02-06 21:49:44 UTC
+++ src/hedlite.c
@@ -45,7 +45,7 @@
 #include "dirname.h"
 
 static a_pcx_image heditrsc;
-static a_pcx_image tile_set_img;
+static a_pcx_image tile_set_img_local;
 
 unsigned short int xdalles = 0;
 unsigned short int ydalles = 0;
@@ -144,9 +144,9 @@ rectangle_copy (int xs, int ys, int xd, int yd,
 static void
 copy_tile (int src_, a_pixel *dest)
 {
-  int i = tile_set_img.width;
+  int i = tile_set_img_local.width;
   int j;
-  a_pixel *src = tile_set_img.buffer + src_;
+  a_pixel *src = tile_set_img_local.buffer + src_;
   for (j = 20; j > 0; j--) {
     fastmem4 (src, dest, 24 >> 2);
     src += i;
@@ -157,9 +157,9 @@ copy_tile (int src_, a_pixel *dest)
 static void
 copy_tile_pcx (int src_, a_pixel *dest)
 {
-  int i = tile_set_img.width;
+  int i = tile_set_img_local.width;
   int j;
-  a_pixel *src = tile_set_img.buffer + src_;
+  a_pixel *src = tile_set_img_local.buffer + src_;
   for (j = 20; j > 0; j--) {
     fastmem4 (src, dest, 24 >> 2);
     src += i;
@@ -170,9 +170,9 @@ copy_tile_pcx (int src_, a_pixel *dest)
 static void
 copy_tile_transp (int src_, a_pixel *dest)
 {
-  int i = tile_set_img.width;
+  int i = tile_set_img_local.width;
   int j, k;
-  a_pixel *src = tile_set_img.buffer + src_;
+  a_pixel *src = tile_set_img_local.buffer + src_;
   for (j = 20; j > 0; j--) {
     for (k = 24; k > 0; k--) {
       if (*src != 0)
@@ -188,9 +188,9 @@ copy_tile_transp (int src_, a_pixel *dest)
 static void
 copy_tile_transp_pcx (int src_, a_pixel *dest)
 {
-  int i = tile_set_img.width;
+  int i = tile_set_img_local.width;
   int j, k;
-  a_pixel *src = tile_set_img.buffer + src_;
+  a_pixel *src = tile_set_img_local.buffer + src_;
   for (j = 20; j > 0; j--) {
     for (k = 24; k > 0; k--) {
       if (*src != 0)
@@ -555,7 +555,7 @@ anim_mod_bcl (int i, int x, int y)
 static void
 update_middle_panel (void)
 {
-  rectangle_copy (xdalles, 0, 144, 200, 145, 0, &tile_set_img);
+  rectangle_copy (xdalles, 0, 144, 200, 145, 0, &tile_set_img_local);
   frame (145 + xdallesdec, ydalles, 23, 19, 15);
   rectangle_copy (0, 64, 30, 6, 290, 64, &heditrsc);
   sprintf (nombre, "%u", (xdalles + xdallesdec) / 24);
@@ -670,7 +670,7 @@ static int
 curdalled (void)
 {
   int i =
-    (xdalles + xdallesdec) / 24 + (ydalles / 20) * (tile_set_img.width / 24);
+    (xdalles + xdallesdec) / 24 + (ydalles / 20) * (tile_set_img_local.width / 24);
   return i;
 }
 
@@ -894,7 +894,7 @@ save_level_as_pcx (void)
   free (tempc);
   putc (0xC, fpcx);
   for (i1 = 0; i1 < 768; i1++)
-    putc (tile_set_img.palette.global[i1] << 2, fpcx);
+    putc (tile_set_img_local.palette.global[i1] << 2, fpcx);
   fclose (fpcx);
 }
 
@@ -1225,7 +1225,7 @@ gestclav (a_keycode i, a_keycode mod)
     }
   } else if (i == HK_End) {
     if (mod & HK_MOD_Ctrl) {
-      xdalles = (tile_set_img.width / 24) * 24 - 144;
+      xdalles = (tile_set_img_local.width / 24) * 24 - 144;
       update_middle_panel ();
     }
   } else if (i == HK_PageDown) {
@@ -1250,7 +1250,7 @@ gestclav (a_keycode i, a_keycode mod)
     }
   } else if (i == HK_Right) {
     if (mod & HK_MOD_Ctrl) {
-      if (xdalles + 168U < tile_set_img.width) {
+      if (xdalles + 168U < tile_set_img_local.width) {
 	xdalles += 24;
 	update_middle_panel ();
       } else if (xdallesdec < 120) {
@@ -1337,7 +1337,7 @@ gestclav (a_keycode i, a_keycode mod)
   } else if (i == HK_Space) {
     j = curdallep ();
     level_map[j].number =
-      xdalles + xdallesdec + ydalles * (tile_set_img.width);
+      xdalles + xdallesdec + ydalles * (tile_set_img_local.width);
     level_map[j].type = ddef[curdalled ()].type;
     level_map[j].info = ddef[curdalled ()].info;
     gestclav (HK_i, HK_MOD_None);
@@ -1351,9 +1351,9 @@ gestclav (a_keycode i, a_keycode mod)
       level_map[j].collision[3] = 0;
     }
     for (j = hplaninfo.xt * hplaninfo.yt - 1; j >= 0; j--) {
-      k = (((level_map[j].number % tile_set_img.width) / 24) +
-	   (level_map[j].number / (tile_set_img.width * 20)) *
-	   (tile_set_img.width / 24));
+      k = (((level_map[j].number % tile_set_img_local.width) / 24) +
+	   (level_map[j].number / (tile_set_img_local.width * 20)) *
+	   (tile_set_img_local.width / 24));
       level_map[j].type = ddef[k].type;
       if (level_map[j].type != t_tunnel) {
 	if (level_map[j].type == t_anim || i == 0x1749)
@@ -1404,7 +1404,7 @@ gestclav (a_keycode i, a_keycode mod)
     if (mod & HK_MOD_Ctrl) {
       for (j = hplaninfo.xt * hplaninfo.yt - 1; j >= 0; j--) {
 	level_map[j].number = xdalles + xdallesdec +
-	  ydalles * (tile_set_img.width);
+	  ydalles * (tile_set_img_local.width);
 	level_map[j].type = ddef[curdalled ()].type;
 	level_map[j].info = ddef[curdalled ()].info;
       }
@@ -1414,7 +1414,7 @@ gestclav (a_keycode i, a_keycode mod)
 
 	level_map[j].number =
 	  (((j % hplaninfo.xt) + (j / hplaninfo.xt)) & 1) * 20 *
-	  tile_set_img.width;
+	  tile_set_img_local.width;
       update_left_panel ();
     }
   } else if (i == HK_F3) {
@@ -1427,7 +1427,7 @@ gestclav (a_keycode i, a_keycode mod)
     if (level_map[curdallep ()].sprite == 0)
 
       level_map[curdallep ()].sprite =
-	(short int) (xdalles + xdallesdec + ydalles * (tile_set_img.width));
+	(short int) (xdalles + xdallesdec + ydalles * (tile_set_img_local.width));
     else
       level_map[curdallep ()].sprite = 0;
     update_left_panel ();
@@ -1707,17 +1707,17 @@ hmain (const char* lname, const char* tset_name,
 				   hplaninfo.tile_set_name), ".pie");
 
   pcx_load_from_rsc ("editor-img", &heditrsc);
-  pcx_load (tile_set_name, &tile_set_img);
+  pcx_load (tile_set_name, &tile_set_img_local);
 
   /* read the tileset definition */
-  XCALLOC_ARRAY (ddef, (tile_set_img.width / 24) * 10);
+  XCALLOC_ARRAY (ddef, (tile_set_img_local.width / 24) * 10);
   if (!((ftmp = fopen (dallepie, "rb")) == NULL))
-    fread (ddef, sizeof (a_tile_info), (tile_set_img.width / 24) * 10, ftmp);
+    fread (ddef, sizeof (a_tile_info), (tile_set_img_local.width / 24) * 10, ftmp);
   fclose (ftmp);
 
   outwayinit ();
   XCALLOC_ARRAY (hedit_buffer, xbuf * 200);
-  set_pal (tile_set_img.palette.global, 0, 256 * 3);
+  set_pal (tile_set_img_local.palette.global, 0, 256 * 3);
   rectangle_copy (0, 0, 30, 200, 290, 0, &heditrsc);
   strupr (levelnomshort);
   draw_text (levelnomshort, 305, 29, 8, 1);
@@ -1767,7 +1767,7 @@ hmain (const char* lname, const char* tset_name,
     free (ddef);
     free (level_map);
     img_free (&heditrsc);
-    img_free (&tile_set_img);
+    img_free (&tile_set_img_local);
   }
 
   free (dallepie);
