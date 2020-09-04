--- src/gif/gif_enc.c.orig	2009-10-03 20:33:17 UTC
+++ src/gif/gif_enc.c
@@ -30,7 +30,7 @@ LOCAL int     gif_img_sz  = 0;
 LOCAL int gen_mpi(uint_8 *src, uint_8 *xtra, uint_8 *dst, 
                   int cnt, uint_8 *pal);
 
-int gif_best_stats[6];
+int gif_best_stat[6];
 
 /* ======================================================================== */
 /*  GIF_START -- Starts a single or multi-frame GIF.                        */
