--- png.c.orig	2002-11-08 10:50:29 UTC
+++ png.c
@@ -74,7 +74,7 @@ SDL_Surface *loadPNG(Uint8 * data, Uint3
    * the normal method of doing things with libpng).  REQUIRED unless you
    * set up your own error handlers in png_create_read_struct() earlier.
    */
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     SDL_SetError("Error reading the PNG file.");
     goto done;
   }
@@ -142,9 +142,9 @@ SDL_Surface *loadPNG(Uint8 * data, Uint3
       Rmask = 0x000000FF;
       Gmask = 0x0000FF00;
       Bmask = 0x00FF0000;
-      Amask = (info_ptr->channels == 4) ? 0xFF000000 : 0;
+      Amask = (png_get_channels(png_ptr, info_ptr) == 4) ? 0xFF000000 : 0;
     } else {
-      int s = (info_ptr->channels == 4) ? 0 : 8;
+      int s = (png_get_channels(png_ptr, info_ptr) == 4) ? 0 : 8;
       Rmask = 0xFF000000 >> s;
       Gmask = 0x00FF0000 >> s;
       Bmask = 0x0000FF00 >> s;
@@ -152,7 +152,7 @@ SDL_Surface *loadPNG(Uint8 * data, Uint3
     }
   }
   surface = SDL_AllocSurface(SDL_SWSURFACE, width, height,
-			     bit_depth * info_ptr->channels, Rmask, Gmask,
+			     bit_depth * png_get_channels(png_ptr, info_ptr), Rmask, Gmask,
 			     Bmask, Amask);
   if (surface == NULL) {
     SDL_SetError("Out of memory");
@@ -188,6 +188,11 @@ SDL_Surface *loadPNG(Uint8 * data, Uint3
   png_read_end(png_ptr, info_ptr);
 
   /* Load the palette, if any */
+  
+  png_uint_32 pnum_palette;
+  png_colorp ppalette;
+  png_get_PLTE(png_ptr, info_ptr, &ppalette, &pnum_palette);
+  
   palette = surface->format->palette;
   if (palette) {
     if (color_type == PNG_COLOR_TYPE_GRAY) {
@@ -197,12 +202,12 @@ SDL_Surface *loadPNG(Uint8 * data, Uint3
 	palette->colors[i].g = i;
 	palette->colors[i].b = i;
       }
-    } else if (info_ptr->num_palette > 0) {
-      palette->ncolors = info_ptr->num_palette;
-      for (i = 0; i < info_ptr->num_palette; ++i) {
-	palette->colors[i].b = info_ptr->palette[i].blue;
-	palette->colors[i].g = info_ptr->palette[i].green;
-	palette->colors[i].r = info_ptr->palette[i].red;
+    } else if ( pnum_palette > 0) {
+      palette->ncolors = pnum_palette;
+      for (i = 0; i < pnum_palette; ++i) {
+	palette->colors[i].b = ppalette[i].blue;
+	palette->colors[i].g = ppalette[i].green;
+	palette->colors[i].r = ppalette[i].red;
       }
     }
   }
