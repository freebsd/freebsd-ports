--- src/gif/gif_enc.h.orig	2006-07-03 05:04:46 UTC
+++ src/gif/gif_enc.h
@@ -21,7 +21,7 @@ typedef struct gif_t
     uint_8  *vid, *pal;
 } gif_t;
 
-int gif_best_stat[6];
+extern int gif_best_stat[6];
 
 /* ======================================================================== */
 /*  GIF_START -- Starts a single or multi-frame GIF.                        */
