--- src/image.c.orig
+++ src/image.c
@@ -1,5 +1,6 @@
 #include <gtk/gtk.h>
 #include <unistd.h>
+#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
@@ -12,6 +13,9 @@
 #include "../pics/neutral.xpm"	// *neutralimage[]
 #include "../pics/treble.xpm"	// *trebleimage[]
 
+void gd_image_change (GDancer *, enum gd_freq_type, gboolean);
+void load_images (GDancer *);
+
 // Clears the pixmaps from memory
 void clear_images_sub (frame *frame)
 {
@@ -109,7 +113,7 @@
 	}
 }
 
-gint load_images (GDancer *dancer)
+void load_images (GDancer *dancer)
 {
 	if (dancer->window == NULL) return; // Make sure dancer exists
 	
@@ -183,7 +187,7 @@
 	gd_move_window (dancer);
 }
 
-gint gd_image_change (GDancer *dancer, enum gd_freq_type newtype, gboolean always_draw)
+void gd_image_change (GDancer *dancer, enum gd_freq_type newtype, gboolean always_draw)
 {
 	static frame *oldtype = NULL;
 	frame *type;
