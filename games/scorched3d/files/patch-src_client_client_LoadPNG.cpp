--- src/client/client/LoadPNG.cpp.orig	2016-06-20 14:16:37 UTC
+++ src/client/client/LoadPNG.cpp
@@ -28,6 +28,8 @@ SDL_Surface *EXT_LoadPNG_RW(SDL_RWops *s
 	int row, i;
 	volatile int ckey = -1;
 	png_color_16 *transv;
+	png_colorp  png_palette;
+	int         num_palette;
 
 	if ( !src ) {
 		/* The error message has been set in SDL_RWFromFile */
@@ -58,7 +60,7 @@ SDL_Surface *EXT_LoadPNG_RW(SDL_RWops *s
 	 * the normal method of doing things with libpng).  REQUIRED unless you
 	 * set up your own error handlers in png_create_read_struct() earlier.
 	 */
-	if ( setjmp(png_ptr->jmpbuf) ) {
+	if ( setjmp(png_jmpbuf(png_ptr)) ) {
 		error = "Error reading the PNG file.";
 		goto done;
 	}
@@ -127,9 +129,9 @@ SDL_Surface *EXT_LoadPNG_RW(SDL_RWops *s
 			Rmask = 0x000000FF;
 			Gmask = 0x0000FF00;
 			Bmask = 0x00FF0000;
-			Amask = (info_ptr->channels == 4) ? 0xFF000000 : 0;
+			Amask = (png_get_channels(png_ptr, info_ptr) == 4) ? 0xFF000000 : 0;
 		} else {
-		        int s = (info_ptr->channels == 4) ? 0 : 8;
+		        int s = (png_get_channels(png_ptr, info_ptr) == 4) ? 0 : 8;
 			Rmask = 0xFF000000 >> s;
 			Gmask = 0x00FF0000 >> s;
 			Bmask = 0x0000FF00 >> s;
@@ -137,7 +139,7 @@ SDL_Surface *EXT_LoadPNG_RW(SDL_RWops *s
 		}
 	}
 	surface = SDL_AllocSurface(SDL_SWSURFACE, width, height,
-			bit_depth*info_ptr->channels, Rmask,Gmask,Bmask,Amask);
+			bit_depth*png_get_channels(png_ptr, info_ptr), Rmask,Gmask,Bmask,Amask);
 	if ( surface == NULL ) {
 		error = "Out of memory";
 		goto done;
@@ -185,12 +187,15 @@ SDL_Surface *EXT_LoadPNG_RW(SDL_RWops *s
 		    palette->colors[i].g = i;
 		    palette->colors[i].b = i;
 		}
-	    } else if (info_ptr->num_palette > 0 ) {
-		palette->ncolors = info_ptr->num_palette; 
-		for( i=0; i<info_ptr->num_palette; ++i ) {
-		    palette->colors[i].b = info_ptr->palette[i].blue;
-		    palette->colors[i].g = info_ptr->palette[i].green;
-		    palette->colors[i].r = info_ptr->palette[i].red;
+	    } else {
+	    	png_get_PLTE(png_ptr, info_ptr, &png_palette, &num_palette);
+	    	if (num_palette > 0 ) {
+			palette->ncolors = num_palette; 
+			for( i=0; i<num_palette; ++i ) {
+			    palette->colors[i].b = png_palette[i].blue;
+			    palette->colors[i].g = png_palette[i].green;
+			    palette->colors[i].r = png_palette[i].red;
+			}
 		}
 	    }
 	}
