--- src/hsetroot.c.bak	Sun Nov 30 19:39:51 2003
+++ src/hsetroot.c	Sun Nov 30 19:37:08 2003
@@ -179,11 +179,13 @@
   if (alpha < 255)
     {
       // Create alpha-override mask
-      imlib_image_set_has_alpha (1);
       Imlib_Color_Modifier modifier = imlib_create_color_modifier ();
+      DATA8 red[256], green[256], blue[256], alph[256];
+
+
+      imlib_image_set_has_alpha (1);
       imlib_context_set_color_modifier (modifier);
 
-      DATA8 red[256], green[256], blue[256], alph[256];
       imlib_get_color_modifier_tables (red, green, blue, alph);
       for (o = 0; o < 256; o++)
 	alph[o] = (DATA8) alpha;
