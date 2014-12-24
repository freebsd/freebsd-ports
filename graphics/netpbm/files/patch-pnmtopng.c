$OpenBSD: patch-converter_other_pnmtopng_c,v 1.2 2011/12/13 21:39:17 naddy Exp $

Fix build with png-1.5.

--- converter/other/pnmtopng.c.orig	Sun Sep 25 20:51:44 2011
+++ converter/other/pnmtopng.c	Tue Dec 13 22:22:04 2011
@@ -61,7 +61,8 @@
 #include <assert.h>
 #include <string.h> /* strcat() */
 #include <limits.h>
-#include <png.h>    /* includes zlib.h and setjmp.h */
+#include <png.h>    /* includes setjmp.h */
+#include <zlib.h>
 #include "pnm.h"
 #include "pngtxt.h"
 #include "shhopt.h"
@@ -69,13 +70,6 @@
 #include "nstring.h"
 #include "version.h"
 
-#if PNG_LIBPNG_VER >= 10400
-#error Your PNG library (<png.h>) is incompatible with this Netpbm source code.
-#error You need either an older PNG library (older than 1.4)
-#error newer Netpbm source code (at least 10.47.04)
-#endif
-
-
 struct zlibCompression {
     /* These are parameters that describe a form of zlib compression.
        Values have the same meaning as the similarly named arguments to
@@ -2098,6 +2092,7 @@ makePngLine(png_byte *           const line,
             gray *               const alpha_mask,
             colorhash_table      const cht,
             coloralphahash_table const caht,
+            png_struct *         const png_ptr,
             png_info *           const info_ptr,
             xelval               const png_maxval,
             unsigned int         const depth) {
@@ -2110,20 +2105,20 @@ makePngLine(png_byte *           const line,
         xel p_png;
         xel const p = xelrow[col];
         PPM_DEPTH(p_png, p, maxval, png_maxval);
-        if (info_ptr->color_type == PNG_COLOR_TYPE_GRAY ||
-            info_ptr->color_type == PNG_COLOR_TYPE_GRAY_ALPHA) {
+        if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY ||
+            png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY_ALPHA) {
             if (depth == 16)
                 *pp++ = PNM_GET1(p_png) >> 8;
             *pp++ = PNM_GET1(p_png) & 0xff;
-        } else if (info_ptr->color_type == PNG_COLOR_TYPE_PALETTE) {
+        } else if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_PALETTE) {
             unsigned int paletteIndex;
             if (alpha)
                 paletteIndex = lookupColorAlpha(caht, &p, &alpha_mask[col]);
             else
                 paletteIndex = ppm_lookupcolor(cht, &p);
             *pp++ = paletteIndex;
-        } else if (info_ptr->color_type == PNG_COLOR_TYPE_RGB ||
-                   info_ptr->color_type == PNG_COLOR_TYPE_RGB_ALPHA) {
+        } else if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB ||
+                   png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB_ALPHA) {
             if (depth == 16)
                 *pp++ = PPM_GETR(p_png) >> 8;
             *pp++ = PPM_GETR(p_png) & 0xff;
@@ -2136,7 +2131,7 @@ makePngLine(png_byte *           const line,
         } else
             pm_error("INTERNAL ERROR: undefined color_type");
                 
-        if (info_ptr->color_type & PNG_COLOR_MASK_ALPHA) {
+        if (png_get_color_type(png_ptr, info_ptr) & PNG_COLOR_MASK_ALPHA) {
             int const png_alphaval = (int)
                 alpha_mask[col] * (float) png_maxval / maxval + 0.5;
             if (depth == 16)
@@ -2193,7 +2188,7 @@ writeRaster(png_struct *         const png_ptr,
             
             makePngLine(line, xelrow, cols, maxval,
                         alpha, alpha ? alpha_mask[row] : NULL,
-                        cht, caht, info_ptr, png_maxval, depth);
+                        cht, caht, png_ptr, info_ptr, png_maxval, depth);
 
             png_write_row(png_ptr, line);
         }
@@ -2205,12 +2200,12 @@ writeRaster(png_struct *         const png_ptr,
 
 static void
 doGamaChunk(struct cmdlineInfo const cmdline,
+            png_struct *       const png_ptr,
             png_info *         const info_ptr) {
             
     if (cmdline.gammaSpec) {
         /* gAMA chunk */
-        info_ptr->valid |= PNG_INFO_gAMA;
-        info_ptr->gamma = cmdline.gamma;
+        png_set_gAMA(png_ptr, info_ptr, cmdline.gamma);
     }
 }
 
@@ -2218,20 +2213,15 @@ doGamaChunk(struct cmdlineInfo const cmdline,
 
 static void
 doChrmChunk(struct cmdlineInfo const cmdline,
+            png_struct *       const png_ptr,
             png_info *         const info_ptr) {
 
     if (cmdline.rgbSpec) {
         /* cHRM chunk */
-        info_ptr->valid |= PNG_INFO_cHRM;
-
-        info_ptr->x_white = cmdline.rgb.wx;
-        info_ptr->y_white = cmdline.rgb.wy;
-        info_ptr->x_red   = cmdline.rgb.rx;
-        info_ptr->y_red   = cmdline.rgb.ry;
-        info_ptr->x_green = cmdline.rgb.gx;
-        info_ptr->y_green = cmdline.rgb.gy;
-        info_ptr->x_blue  = cmdline.rgb.bx;
-        info_ptr->y_blue  = cmdline.rgb.by;
+	
+        png_set_cHRM (png_ptr, info_ptr, cmdline.rgb.wx, cmdline.rgb.wy,
+                      cmdline.rgb.rx, cmdline.rgb.ry, cmdline.rgb.gx,
+                      cmdline.rgb.gy, cmdline.rgb.bx, cmdline.rgb.by);
     }
 }
 
@@ -2239,15 +2229,12 @@ doChrmChunk(struct cmdlineInfo const cmdline,
 
 static void
 doPhysChunk(struct cmdlineInfo const cmdline,
+            png_struct *       const png_ptr,
             png_info *         const info_ptr) {
 
     if (cmdline.sizeSpec) {
         /* pHYS chunk */
-        info_ptr->valid |= PNG_INFO_pHYs;
-
-        info_ptr->x_pixels_per_unit = cmdline.size.x;
-        info_ptr->y_pixels_per_unit = cmdline.size.y;
-        info_ptr->phys_unit_type    = cmdline.size.unit;
+        png_set_pHYs(png_ptr, info_ptr, cmdline.size.x, cmdline.size.y, cmdline.size.unit);
     }
 }
 
@@ -2256,26 +2243,28 @@ doPhysChunk(struct cmdlineInfo const cmdline,
 
 static void
 doTimeChunk(struct cmdlineInfo const cmdline,
+            png_struct *       const png_ptr,
             png_info *         const info_ptr) {
 
     if (cmdline.modtimeSpec) {
         /* tIME chunk */
-        info_ptr->valid |= PNG_INFO_tIME;
-
-        png_convert_from_time_t(&info_ptr->mod_time, cmdline.modtime);
+        png_timep ptime;
+        png_convert_from_time_t(ptime, cmdline.modtime);
+        png_set_tIME(png_ptr, info_ptr, ptime);
     }
 }
 
 
 
 static void
-doSbitChunk(png_info * const pngInfoP,
+doSbitChunk(png_struct * const pngP,
+            png_info * const pngInfoP,
             xelval     const pngMaxval,
             xelval     const maxval,
             bool       const alpha,
             xelval     const alphaMaxval) {
 
-    if (pngInfoP->color_type != PNG_COLOR_TYPE_PALETTE &&
+    if (png_get_color_type(pngP, pngInfoP) != PNG_COLOR_TYPE_PALETTE &&
         (pngMaxval > maxval || (alpha && pngMaxval > alphaMaxval))) {
 
         /* We're writing in a bit depth that doesn't match the maxval
@@ -2294,27 +2283,29 @@ doSbitChunk(png_info * const pngInfoP,
            sBIT chunk.
         */
 
-        pngInfoP->valid |= PNG_INFO_sBIT;
-
         {
             int const sbitval = pm_maxvaltobits(MIN(maxval, pngMaxval));
+            png_color_8 sbit;
 
-            if (pngInfoP->color_type & PNG_COLOR_MASK_COLOR) {
-                pngInfoP->sig_bit.red   = sbitval;
-                pngInfoP->sig_bit.green = sbitval;
-                pngInfoP->sig_bit.blue  = sbitval;
+            (void)memset(&sbit, 0, sizeof(sbit));
+            if (png_get_color_type(pngP, pngInfoP) & PNG_COLOR_MASK_COLOR) {
+                sbit.red   = sbitval;
+                sbit.green = sbitval;
+                sbit.blue  = sbitval;
             } else
-                pngInfoP->sig_bit.gray = sbitval;
+                sbit.gray = sbitval;
             
             if (verbose)
                 pm_message("Writing sBIT chunk with bits = %d", sbitval);
+
+            if (png_get_color_type(pngP, pngInfoP) & PNG_COLOR_MASK_ALPHA) {
+                sbit.alpha =
+                    pm_maxvaltobits(MIN(alphaMaxval, pngMaxval));
+                if (verbose)
+                    pm_message("  alpha bits = %d", sbit.alpha);
+            }
+            png_set_sBIT(pngP, pngInfoP, &sbit);
         }
-        if (pngInfoP->color_type & PNG_COLOR_MASK_ALPHA) {
-            pngInfoP->sig_bit.alpha =
-                pm_maxvaltobits(MIN(alphaMaxval, pngMaxval));
-            if (verbose)
-                pm_message("  alpha bits = %d", pngInfoP->sig_bit.alpha);
-        }
     }
 }
 
@@ -2410,6 +2401,8 @@ convertpnm(struct cmdlineInfo const cmdline,
   xelval maxmaxval;
   gray ** alpha_mask;
 
+  int color_type;
+
   /* these guys are initialized to quiet compiler warnings: */
   maxmaxval = 255;
   alpha_mask = NULL;
@@ -2595,43 +2588,42 @@ convertpnm(struct cmdlineInfo const cmdline,
     pm_error ("setjmp returns error condition (2)");
   }
 
-  png_init_io (png_ptr, stdout);
-  info_ptr->width = cols;
-  info_ptr->height = rows;
-  info_ptr->bit_depth = depth;
-
   if (colorMapped)
-    info_ptr->color_type = PNG_COLOR_TYPE_PALETTE;
-  else if (pnm_type == PPM_TYPE)
-    info_ptr->color_type = PNG_COLOR_TYPE_RGB;
-  else
-    info_ptr->color_type = PNG_COLOR_TYPE_GRAY;
+    color_type = PNG_COLOR_TYPE_PALETTE;
+  else if (pnm_type == PPM_TYPE) {
+    if (alpha)
+      color_type = PNG_COLOR_TYPE_RGB_ALPHA;
+    else
+      color_type = PNG_COLOR_TYPE_RGB;
+  } else {
+    if (alpha)
+      color_type = PNG_COLOR_TYPE_GRAY_ALPHA;
+    else
+      color_type = PNG_COLOR_TYPE_GRAY;
+  }
 
-  if (alpha && info_ptr->color_type != PNG_COLOR_TYPE_PALETTE)
-    info_ptr->color_type |= PNG_COLOR_MASK_ALPHA;
+  png_set_IHDR(png_ptr, info_ptr, cols, rows, depth, color_type, 0, 0, 0);
+  png_init_io (png_ptr, stdout);
 
-  info_ptr->interlace_type = cmdline.interlace;
+  if (cmdline.interlace)
+    png_set_interlace_handling(png_ptr);
 
-  doGamaChunk(cmdline, info_ptr);
+  doGamaChunk(cmdline, png_ptr, info_ptr);
 
-  doChrmChunk(cmdline, info_ptr);
+  doChrmChunk(cmdline, png_ptr, info_ptr);
 
-  doPhysChunk(cmdline, info_ptr);
+  doPhysChunk(cmdline, png_ptr, info_ptr);
 
-  if (info_ptr->color_type == PNG_COLOR_TYPE_PALETTE) {
+  if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_PALETTE) {
 
     /* creating PNG palette  (PLTE and tRNS chunks) */
 
     createPngPalette(palette_pnm, palette_size, maxval,
                      trans_pnm, trans_size, alpha_maxval, 
                      palette, trans);
-    info_ptr->valid |= PNG_INFO_PLTE;
-    info_ptr->palette = palette;
-    info_ptr->num_palette = palette_size;
+    png_set_PLTE(png_ptr, info_ptr, palette, palette_size);
     if (trans_size > 0) {
-        info_ptr->valid |= PNG_INFO_tRNS;
-        info_ptr->trans = trans;
-        info_ptr->num_trans = trans_size;   /* omit opaque values */
+        png_set_tRNS(png_ptr, info_ptr, trans, trans_size, NULL);
     }
     /* creating hIST chunk */
     if (cmdline.hist) {
@@ -2657,18 +2649,17 @@ convertpnm(struct cmdlineInfo const cmdline,
 
         ppm_freecolorhash(cht);
 
-        info_ptr->valid |= PNG_INFO_hIST;
-        info_ptr->hist = histogram;
+        png_set_hIST(png_ptr, info_ptr, histogram);
         if (verbose)
             pm_message("histogram created");
     }
   } else { /* color_type != PNG_COLOR_TYPE_PALETTE */
-    if (info_ptr->color_type == PNG_COLOR_TYPE_GRAY ||
-        info_ptr->color_type == PNG_COLOR_TYPE_RGB) {
+    if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY ||
+        png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB) {
         if (transparent > 0) {
-            info_ptr->valid |= PNG_INFO_tRNS;
-            info_ptr->trans_values = 
-                xelToPngColor_16(transcolor, maxval, png_maxval);
+            png_color_16 trans_color = xelToPngColor_16(transcolor, maxval, png_maxval);
+            png_set_tRNS(png_ptr, info_ptr, NULL, 0, &trans_color);
+                
         }
     } else {
         /* This is PNG_COLOR_MASK_ALPHA.  Transparency will be handled
@@ -2676,43 +2667,49 @@ convertpnm(struct cmdlineInfo const cmdline,
         */
     }
     if (verbose) {
-        if (info_ptr->valid && PNG_INFO_tRNS) 
+        if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS)) {
+            png_color_16p trans_color;
+
+            png_get_tRNS(png_ptr, info_ptr, NULL, NULL, &trans_color);
             pm_message("Transparent color {gray, red, green, blue} = "
                        "{%d, %d, %d, %d}",
-                       info_ptr->trans_values.gray,
-                       info_ptr->trans_values.red,
-                       info_ptr->trans_values.green,
-                       info_ptr->trans_values.blue);
-        else
+                       trans_color->gray,
+                       trans_color->red,
+                       trans_color->green,
+                       trans_color->blue);
+        } else
             pm_message("No transparent color");
     }
   }
 
   /* bKGD chunk */
   if (cmdline.background) {
-      info_ptr->valid |= PNG_INFO_bKGD;
-      if (info_ptr->color_type == PNG_COLOR_TYPE_PALETTE) {
-          info_ptr->background.index = background_index;
+      if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_PALETTE) {
+          png_color_16 background;
+
+          (void)memset(&background, 0, sizeof(background));
+          background.index = background_index;
+          png_set_bKGD(png_ptr, info_ptr, &background);
       } else {
-          info_ptr->background = 
-              xelToPngColor_16(backcolor, maxval, png_maxval);
+          png_color_16 background = xelToPngColor_16(backcolor, maxval, png_maxval);
+          png_set_bKGD(png_ptr, info_ptr, &background);
           if (verbose)
               pm_message("Writing bKGD chunk with background color "
                          " {gray, red, green, blue} = {%d, %d, %d, %d}",
-                         info_ptr->background.gray, 
-                         info_ptr->background.red, 
-                         info_ptr->background.green, 
-                         info_ptr->background.blue ); 
+                         background.gray, 
+                         background.red, 
+                         background.green, 
+                         background.blue ); 
       }
   }
 
-  doSbitChunk(info_ptr, png_maxval, maxval, alpha, alpha_maxval);
+  doSbitChunk(png_ptr, info_ptr, png_maxval, maxval, alpha, alpha_maxval);
 
   /* tEXT and zTXT chunks */
   if (cmdline.text || cmdline.ztxt)
-      pnmpng_read_text(info_ptr, tfp, !!cmdline.ztxt, cmdline.verbose);
+      pnmpng_read_text(png_ptr, info_ptr, tfp, !!cmdline.ztxt, cmdline.verbose);
 
-  doTimeChunk(cmdline, info_ptr);
+  doTimeChunk(cmdline, png_ptr, info_ptr);
 
   if (cmdline.filterSet != 0)
       png_set_filter(png_ptr, 0, cmdline.filterSet);
@@ -2722,6 +2719,7 @@ convertpnm(struct cmdlineInfo const cmdline,
   /* write the png-info struct */
   png_write_info(png_ptr, info_ptr);
 
+#if 0
   if (cmdline.text || cmdline.ztxt)
       /* prevent from being written twice with png_write_end */
       info_ptr->num_text = 0;
@@ -2729,6 +2727,7 @@ convertpnm(struct cmdlineInfo const cmdline,
   if (cmdline.modtime)
       /* prevent from being written twice with png_write_end */
       info_ptr->valid &= ~PNG_INFO_tIME;
+#endif
 
   /* let libpng take care of, e.g., bit-depth conversions */
   png_set_packing (png_ptr);
