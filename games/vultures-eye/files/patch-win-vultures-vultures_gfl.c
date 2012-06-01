--- win/vultures/vultures_gfl.c.orig	2006-06-06 21:23:28.000000000 +0200
+++ win/vultures/vultures_gfl.c	2012-05-03 22:41:55.000000000 +0200
@@ -11,9 +11,10 @@
 #endif
 
 #include <SDL.h>
-#include <SDL_image.h>
+/* #include <SDL_image.h> */
 
 #include "png.h"
+#include "pngpriv.h"
 
 #include "vultures_gfl.h"
 #include "vultures_gen.h"
@@ -73,7 +74,7 @@
         goto out;
 
     /* Set up error handling */
-    if (setjmp(png_ptr->jmpbuf))
+    if (setjmp(png_jmpbuf(png_ptr)))
         goto out;
 
     png_set_read_fn(png_ptr, (char *)srcbuf, vultures_png_read_callback);
