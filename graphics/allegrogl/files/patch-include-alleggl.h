--- include/alleggl.h.orig	Thu Jan 22 14:12:08 2004
+++ include/alleggl.h	Thu Jan 22 14:12:21 2004
@@ -48,9 +48,11 @@
 #include "allegrogl/gl_ext.h"
 
 #ifdef ALLEGRO_WITH_XWINDOWS
+/*
 #ifndef HAVE_LIBPTHREAD
 #   error AllegroGL requires Allegro to have pthread support enabled!
 #endif
+*/
 #include <alleggl_config.h>
 #endif
 
