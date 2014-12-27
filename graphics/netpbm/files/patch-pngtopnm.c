$OpenBSD: patch-converter_other_pngtopnm_c,v 1.2 2011/12/13 21:39:17 naddy Exp $

Fix build with png-1.5.

--- converter/other/pngtopnm.c.orig	Fri Nov 25 01:15:46 2011
+++ converter/other/pngtopnm.c	Tue Dec 13 22:25:03 2011
@@ -44,12 +44,6 @@
 #include "nstring.h"
 #include "shhopt.h"
 
-#if PNG_LIBPNG_VER >= 10400
-#error Your PNG library (<png.h>) is incompatible with this Netpbm source code.
-#error You need either an older PNG library (older than 1.4)
-#error newer Netpbm source code (at least 10.48)
-#endif
-
 typedef struct _jmpbuf_wrapper {
   jmp_buf jmpbuf;
 } jmpbuf_wrapper;
@@ -187,7 +181,7 @@ parseCommandLine(int                 argc, 
 
 
 
-#define get_png_val(p) _get_png_val (&(p), info_ptr->bit_depth)
+#define get_png_val(p) _get_png_val (&(p), png_get_bit_depth(png_ptr, info_ptr))
 
 static png_uint_16
 _get_png_val (png_byte ** const pp,
@@ -266,33 +260,39 @@ png_color c;
 }
 
 #ifdef __STDC__
-static void save_text (png_info *info_ptr, FILE *tfp)
+static void save_text (png_structp png_ptr, png_info *info_ptr, FILE *tfp)
 #else
-static void save_text (info_ptr, tfp)
+static void save_text (png_ptr, info_ptr, tfp)
+png_structp png_ptr;
 png_info *info_ptr;
 FILE *tfp;
 #endif
 {
   int i, j, k;
+  png_textp text_ptr;
+  int num_text;
 
-  for (i = 0 ; i < info_ptr->num_text ; i++) {
+  if (png_get_text(png_ptr, info_ptr, &text_ptr, &num_text) == 0)
+    return;
+
+  for (i = 0 ; i < num_text ; i++) {
     j = 0;
-    while (info_ptr->text[i].key[j] != '\0' && info_ptr->text[i].key[j] != ' ')
+    while (text_ptr[i].key[j] != '\0' && text_ptr[i].key[j] != ' ')
       j++;    
-    if (info_ptr->text[i].key[j] != ' ') {
-      fprintf (tfp, "%s", info_ptr->text[i].key);
-      for (j = strlen (info_ptr->text[i].key) ; j < 15 ; j++)
+    if (text_ptr[i].key[j] != ' ') {
+      fprintf (tfp, "%s", text_ptr[i].key);
+      for (j = strlen (text_ptr[i].key) ; j < 15 ; j++)
         putc (' ', tfp);
     } else {
-      fprintf (tfp, "\"%s\"", info_ptr->text[i].key);
-      for (j = strlen (info_ptr->text[i].key) ; j < 13 ; j++)
+      fprintf (tfp, "\"%s\"", text_ptr[i].key);
+      for (j = strlen (text_ptr[i].key) ; j < 13 ; j++)
         putc (' ', tfp);
     }
     putc (' ', tfp); /* at least one space between key and text */
     
-    for (j = 0 ; j < info_ptr->text[i].text_length ; j++) {
-      putc (info_ptr->text[i].text[j], tfp);
-      if (info_ptr->text[i].text[j] == '\n')
+    for (j = 0 ; j < text_ptr[i].text_length ; j++) {
+      putc (text_ptr[i].text[j], tfp);
+      if (text_ptr[i].text[j] == '\n')
         for (k = 0 ; k < 16 ; k++)
           putc ((int)' ', tfp);
     }
@@ -301,9 +301,10 @@ FILE *tfp;
 }
 
 #ifdef __STDC__
-static void show_time (png_info *info_ptr)
+static void show_time (png_structp png_ptr, png_info *info_ptr)
 #else
-static void show_time (info_ptr)
+static void show_time (png_ptr, info_ptr)
+png_structp png_ptr;
 png_info *info_ptr;
 #endif
 {
@@ -311,19 +312,20 @@ png_info *info_ptr;
         "", "January", "February", "March", "April", "May", "June",
         "July", "August", "September", "October", "November", "December"
     };
+  png_timep mod_time;
 
-  if (info_ptr->valid & PNG_INFO_tIME) {
-    if (info_ptr->mod_time.month < 1 ||
-      info_ptr->mod_time.month >= ARRAY_SIZE(month)) {
+  if (png_get_tIME(png_ptr, info_ptr, &mod_time) & PNG_INFO_tIME) {
+    if (mod_time->month < 1 ||
+      mod_time->month >= ARRAY_SIZE(month)) {
       pm_message("tIME chunk in PNG input is invalid; "
                  "modification time of image is unknown.  "
                  "The month value, which should be in the range "
-                 "1-12, is %u", info_ptr->mod_time.month);
+                 "1-12, is %u", mod_time->month);
     } else
     pm_message ("modification time: %02d %s %d %02d:%02d:%02d",
-                info_ptr->mod_time.day, month[info_ptr->mod_time.month],
-                info_ptr->mod_time.year, info_ptr->mod_time.hour,
-                info_ptr->mod_time.minute, info_ptr->mod_time.second);
+                mod_time->day, month[mod_time->month],
+                mod_time->year, mod_time->hour,
+                mod_time->minute, mod_time->second);
   }
 }
 
@@ -360,12 +362,28 @@ png_const_charp msg;
 
 
 static void
-dump_png_info(png_info *info_ptr) {
+dump_png_info(png_structp png_ptr, png_info *info_ptr) {
 
     const char *type_string;
     const char *filter_string;
+    png_color_16p background;
+    int num_trans;
+    double gamma;
+    png_color_8p sig_bit;
+    png_colorp palette;
+    int num_palette;
+    png_uint_16p hist;
+    int res_x, res_y, unit_type;
+    png_int_32 offset_x, offset_y;
+    png_timep mod_time;
+    png_charp purpose;
+    png_int_32 X0, X1;
+    int type, nparams;
+    png_charp units;
+    png_charpp params;
+    int file_srgb_intent;
 
-    switch (info_ptr->color_type) {
+    switch (png_get_color_type(png_ptr, info_ptr)) {
       case PNG_COLOR_TYPE_GRAY:
         type_string = "gray";
         break;
@@ -387,90 +405,101 @@ dump_png_info(png_info *info_ptr) {
         break;
     }
 
-    switch (info_ptr->filter_type) {
+    switch (png_get_filter_type(png_ptr, info_ptr)) {
     case PNG_FILTER_TYPE_BASE:
         asprintfN(&filter_string, "base filter");
         break;
     default:
         asprintfN(&filter_string, "unknown filter type %d", 
-                  info_ptr->filter_type);
+                  png_get_filter_type(png_ptr, info_ptr));
     }
 
-    pm_message("reading a %ldw x %ldh image, %d bit%s",
-               info_ptr->width, info_ptr->height,
-               info_ptr->bit_depth, info_ptr->bit_depth > 1 ? "s" : "");
+    pm_message("reading a %uw x %uh image, %d bit%s",
+               png_get_image_width(png_ptr, info_ptr),
+               png_get_image_height(png_ptr, info_ptr),
+               png_get_bit_depth(png_ptr, info_ptr),
+               png_get_bit_depth(png_ptr, info_ptr) > 1 ? "s" : "");
     pm_message("%s, %s, %s",
                type_string,
-               info_ptr->interlace_type ? 
+               png_get_interlace_type(png_ptr, info_ptr) ? 
                "Adam7 interlaced" : "not interlaced",
                filter_string);
-    pm_message("background {index, gray, red, green, blue} = "
-               "{%d, %d, %d, %d, %d}",
-               info_ptr->background.index,
-               info_ptr->background.gray,
-               info_ptr->background.red,
-               info_ptr->background.green,
-               info_ptr->background.blue);
 
+    if (png_get_bKGD(png_ptr, info_ptr, &background) & PNG_INFO_bKGD) {
+      pm_message("background {index, gray, red, green, blue} = "
+                 "{%d, %d, %d, %d, %d}",
+                 background->index,
+                 background->gray,
+                 background->red,
+                 background->green,
+                 background->blue);
+   }
+
     strfree(filter_string);
 
-    if (info_ptr->valid & PNG_INFO_tRNS)
+    if (png_get_tRNS(png_ptr, info_ptr,
+                     NULL, &num_trans, NULL) & PNG_INFO_tRNS)
         pm_message("tRNS chunk (transparency): %u entries",
-                   info_ptr->num_trans);
+                   num_trans);
     else
         pm_message("tRNS chunk (transparency): not present");
 
-    if (info_ptr->valid & PNG_INFO_gAMA)
-        pm_message("gAMA chunk (image gamma): gamma = %4.2f", info_ptr->gamma);
+    if (png_get_gAMA(png_ptr, info_ptr, &gamma) & PNG_INFO_gAMA)
+        pm_message("gAMA chunk (image gamma): gamma = %4.2f", gamma);
     else
         pm_message("gAMA chunk (image gamma): not present");
 
-    if (info_ptr->valid & PNG_INFO_sBIT)
+    if (png_get_sBIT(png_ptr, info_ptr, &sig_bit) & PNG_INFO_sBIT)
         pm_message("sBIT chunk: present");
     else
         pm_message("sBIT chunk: not present");
 
-    if (info_ptr->valid & PNG_INFO_cHRM)
+    if (png_get_cHRM(png_ptr, info_ptr,
+                     NULL, NULL, NULL, NULL,
+                     NULL, NULL, NULL, NULL) & PNG_INFO_cHRM)
         pm_message("cHRM chunk: present");
     else
         pm_message("cHRM chunk: not present");
 
-    if (info_ptr->valid & PNG_INFO_PLTE)
-        pm_message("PLTE chunk: %d entries", info_ptr->num_palette);
+    if (png_get_PLTE(png_ptr, info_ptr, &palette, &num_palette) & PNG_INFO_PLTE)
+        pm_message("PLTE chunk: %d entries", num_palette);
     else
         pm_message("PLTE chunk: not present");
 
-    if (info_ptr->valid & PNG_INFO_bKGD)
+    if (png_get_bKGD(png_ptr, info_ptr, &background) & PNG_INFO_bKGD)
         pm_message("bKGD chunk: present");
     else
         pm_message("bKGD chunk: not present");
 
-    if (info_ptr->valid & PNG_INFO_hIST)
+    if (png_get_hIST(png_ptr, info_ptr, &hist) & PNG_INFO_hIST)
         pm_message("hIST chunk: present");
     else
         pm_message("hIST chunk: not present");
 
-    if (info_ptr->valid & PNG_INFO_pHYs)
+    if (png_get_pHYs(png_ptr, info_ptr,
+                     &res_x, &res_y, &unit_type) & PNG_INFO_pHYs)
         pm_message("pHYs chunk: present");
     else
         pm_message("pHYs chunk: not present");
 
-    if (info_ptr->valid & PNG_INFO_oFFs)
+    if (png_get_oFFs(png_ptr, info_ptr,
+                     &offset_x, &offset_y, &unit_type) & PNG_INFO_oFFs)
         pm_message("oFFs chunk: present");
     else
         pm_message("oFFs chunk: not present");
 
-    if (info_ptr->valid & PNG_INFO_tIME)
+    if (png_get_tIME(png_ptr, info_ptr, &mod_time) & PNG_INFO_tIME)
         pm_message("tIME chunk: present");
     else
         pm_message("tIME chunk: not present");
 
-    if (info_ptr->valid & PNG_INFO_pCAL)
+    if (png_get_pCAL(png_ptr, info_ptr, &purpose, &X0, &X1,
+                     &type, &nparams, &units, &params) & PNG_INFO_pCAL)
         pm_message("pCAL chunk: present");
     else
         pm_message("pCAL chunk: not present");
 
-    if (info_ptr->valid & PNG_INFO_sRGB)
+    if (png_get_sRGB(png_ptr, info_ptr, &file_srgb_intent) & PNG_INFO_sRGB)
         pm_message("sRGB chunk: present");
     else
         pm_message("sRGB chunk: not present");
@@ -479,19 +508,19 @@ dump_png_info(png_info *info_ptr) {
 
 
 static bool
-isTransparentColor(pngcolor   const color,
-                   png_info * const info_ptr,
-                   double     const totalgamma) {
+isTransparentColor(pngcolor    const color,
+                   png_structp const png_ptr,
+                   png_info  * const info_ptr,
+                   double      const totalgamma) {
 /*----------------------------------------------------------------------------
    Return TRUE iff pixels of color 'color' are supposed to be transparent
    everywhere they occur.  Assume it's an RGB image.
 -----------------------------------------------------------------------------*/
     bool retval;
+    png_color_16p transColorP;
 
-    if (info_ptr->valid & PNG_INFO_tRNS) {
-        const png_color_16 * const transColorP = &info_ptr->trans_values;
-    
-
+    if (png_get_tRNS(png_ptr, info_ptr,
+                     NULL, NULL, &transColorP) & PNG_INFO_tRNS) {
         /* There seems to be a problem here: you can't compare real
            numbers for equality.  Also, I'm not sure the gamma
            corrected/uncorrected color spaces are right here.  
@@ -537,9 +566,11 @@ setupGammaCorrection(png_struct * const png_ptr,
     if (displaygamma == -1.0)
         *totalgammaP = -1.0;
     else {
+        double fileGamma;
         float imageGamma;
-        if (info_ptr->valid & PNG_INFO_gAMA)
-            imageGamma = info_ptr->gamma;
+
+        if (png_get_gAMA(png_ptr, info_ptr, &fileGamma) & PNG_INFO_gAMA)
+            imageGamma = fileGamma;
         else {
             if (verbose)
                 pm_message("PNG doesn't specify image gamma.  Assuming 1.0");
@@ -555,10 +586,14 @@ setupGammaCorrection(png_struct * const png_ptr,
         } else {
             png_set_gamma(png_ptr, displaygamma, imageGamma);
             *totalgammaP = imageGamma * displaygamma;
+#ifdef NOT_SUPPORTED_ANYMORE
+            /* The API doesn't clearing PNG_INFO_sBIT. */
+
             /* in case of gamma-corrections, sBIT's as in the
                PNG-file are not valid anymore 
             */
             info_ptr->valid &= ~PNG_INFO_sBIT;
+#endif
             if (verbose)
                 pm_message("image gamma is %4.2f, "
                            "converted for display gamma of %4.2f",
@@ -570,20 +605,24 @@ setupGammaCorrection(png_struct * const png_ptr,
 
 
 static bool
-paletteHasPartialTransparency(png_info * const info_ptr) {
+paletteHasPartialTransparency(png_structp png_ptr, png_info * const info_ptr) {
 
     bool retval;
 
-    if (info_ptr->color_type == PNG_COLOR_TYPE_PALETTE) {
-        if (info_ptr->valid & PNG_INFO_tRNS) {
+    if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_PALETTE) {
+      png_bytep trans_alpha;
+      int num_trans;
+
+      if (png_get_tRNS(png_ptr, info_ptr,
+                       &trans_alpha, &num_trans, NULL) & PNG_INFO_tRNS) {
             bool foundGray;
             unsigned int i;
             
             for (i = 0, foundGray = FALSE;
-                 i < info_ptr->num_trans && !foundGray;
+                 i < num_trans && !foundGray;
                  ++i) {
-                if (info_ptr->trans[i] != 0 &&
-                    info_ptr->trans[i] != maxval) {
+                if (trans_alpha[i] != 0 &&
+                    trans_alpha[i] != maxval) {
                     foundGray = TRUE;
                 }
             }
@@ -611,14 +650,16 @@ setupSignificantBits(png_struct *        const png_ptr
 
   Return the result as *maxvalP.
 -----------------------------------------------------------------------------*/
+    png_color_8p sig_bit;
+
     /* Initial assumption of maxval */
-    if (info_ptr->color_type == PNG_COLOR_TYPE_PALETTE) {
+    if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_PALETTE) {
         if (alpha == ALPHA_ONLY) {
-            if (info_ptr->color_type == PNG_COLOR_TYPE_GRAY ||
-                info_ptr->color_type == PNG_COLOR_TYPE_RGB)
+            if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY ||
+                png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB)
                 /* The alpha mask will be all opaque, so maxval 1 is plenty */
                 *maxvalP = 1;
-            else if (paletteHasPartialTransparency(info_ptr))
+            else if (paletteHasPartialTransparency(png_ptr, info_ptr))
                 /* Use same maxval as PNG transparency palette for simplicity*/
                 *maxvalP = 255;
             else
@@ -628,7 +669,7 @@ setupSignificantBits(png_struct *        const png_ptr
             /* Use same maxval as PNG palette for simplicity */
             *maxvalP = 255;
     } else {
-        *maxvalP = (1l << info_ptr->bit_depth) - 1;
+        *maxvalP = (1l << png_get_bit_depth(png_ptr, info_ptr)) - 1;
     }
 
     /* sBIT handling is very tricky. If we are extracting only the
@@ -641,20 +682,26 @@ setupSignificantBits(png_struct *        const png_ptr
        is used 
     */
     
-    if (info_ptr->valid & PNG_INFO_sBIT) {
+    if (png_get_sBIT(png_ptr, info_ptr, &sig_bit) & PNG_INFO_sBIT) {
+        png_byte color_type;
+        png_bytep trans_alpha;
+        int num_trans;
+
+        color_type = png_get_color_type(png_ptr, info_ptr);
         switch (alpha) {
         case ALPHA_MIX:
-            if (info_ptr->color_type == PNG_COLOR_TYPE_RGB_ALPHA ||
-                info_ptr->color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
+            if (color_type == PNG_COLOR_TYPE_RGB_ALPHA ||
+                color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
                 break;
-            if (info_ptr->color_type == PNG_COLOR_TYPE_PALETTE &&
-                (info_ptr->valid & PNG_INFO_tRNS)) {
+            if (color_type == PNG_COLOR_TYPE_PALETTE &&
+                png_get_tRNS(png_ptr, info_ptr,
+                             &trans_alpha, &num_trans, NULL) & PNG_INFO_tRNS) {
 
                 bool trans_mix;
                 unsigned int i;
                 trans_mix = TRUE;
-                for (i = 0; i < info_ptr->num_trans; ++i)
-                    if (info_ptr->trans[i] != 0 && info_ptr->trans[i] != 255) {
+                for (i = 0; i < num_trans; ++i)
+                    if (trans_alpha[i] != 0 && trans_alpha[i] != 255) {
                         trans_mix = FALSE;
                         break;
                     }
@@ -665,70 +712,76 @@ setupSignificantBits(png_struct *        const png_ptr
             /* else fall though to normal case */
 
         case ALPHA_NONE:
-            if ((info_ptr->color_type == PNG_COLOR_TYPE_PALETTE ||
-                 info_ptr->color_type == PNG_COLOR_TYPE_RGB ||
-                 info_ptr->color_type == PNG_COLOR_TYPE_RGB_ALPHA) &&
-                (info_ptr->sig_bit.red != info_ptr->sig_bit.green ||
-                 info_ptr->sig_bit.red != info_ptr->sig_bit.blue) &&
+            if ((color_type == PNG_COLOR_TYPE_PALETTE ||
+                 color_type == PNG_COLOR_TYPE_RGB ||
+                 color_type == PNG_COLOR_TYPE_RGB_ALPHA) &&
+                (sig_bit->red != sig_bit->green ||
+                 sig_bit->red != sig_bit->blue) &&
                 alpha == ALPHA_NONE) {
                 pm_message("This program cannot handle "
                            "different bit depths for color channels");
                 pm_message("writing file with %d bit resolution",
-                           info_ptr->bit_depth);
+                           png_get_bit_depth(png_ptr, info_ptr));
                 *errorlevelP = PNMTOPNG_WARNING_LEVEL;
             } else {
-                if ((info_ptr->color_type == PNG_COLOR_TYPE_PALETTE) &&
-                    (info_ptr->sig_bit.red < 255)) {
+                png_colorp palette;
+                int num_palette;
+
+                if ((color_type == PNG_COLOR_TYPE_PALETTE) &&
+                    (sig_bit->red < 255) &&
+                    png_get_PLTE(png_ptr, info_ptr,
+                                 &palette, &num_palette) & PNG_INFO_PLTE) {
                     unsigned int i;
-                    for (i = 0; i < info_ptr->num_palette; ++i) {
-                        info_ptr->palette[i].red   >>=
-                            (8 - info_ptr->sig_bit.red);
-                        info_ptr->palette[i].green >>=
-                            (8 - info_ptr->sig_bit.green);
-                        info_ptr->palette[i].blue  >>=
-                            (8 - info_ptr->sig_bit.blue);
+
+                    for (i = 0; i < num_palette; ++i) {
+                        palette[i].red   >>=
+                            (8 - sig_bit->red);
+                        palette[i].green >>=
+                            (8 - sig_bit->green);
+                        palette[i].blue  >>=
+                            (8 - sig_bit->blue);
                     }
-                    *maxvalP = (1l << info_ptr->sig_bit.red) - 1;
+                    *maxvalP = (1l << sig_bit->red) - 1;
                     if (verbose)
                         pm_message ("image has fewer significant bits, "
                                     "writing file with %d bits per channel", 
-                                    info_ptr->sig_bit.red);
+                                    sig_bit->red);
                 } else
-                    if ((info_ptr->color_type == PNG_COLOR_TYPE_RGB ||
-                         info_ptr->color_type == PNG_COLOR_TYPE_RGB_ALPHA) &&
-                        (info_ptr->sig_bit.red < info_ptr->bit_depth)) {
-                        png_set_shift (png_ptr, &(info_ptr->sig_bit));
-                        *maxvalP = (1l << info_ptr->sig_bit.red) - 1;
+                    if ((color_type == PNG_COLOR_TYPE_RGB ||
+                         color_type == PNG_COLOR_TYPE_RGB_ALPHA) &&
+                        (sig_bit->red < png_get_bit_depth(png_ptr, info_ptr))) {
+                        png_set_shift (png_ptr, sig_bit);
+                        *maxvalP = (1l << sig_bit->red) - 1;
                         if (verbose)
                             pm_message("image has fewer significant bits, "
                                        "writing file with %d "
                                        "bits per channel", 
-                                       info_ptr->sig_bit.red);
+                                       sig_bit->red);
                     } else 
-                        if ((info_ptr->color_type == PNG_COLOR_TYPE_GRAY ||
-                             info_ptr->color_type ==
+                        if ((color_type == PNG_COLOR_TYPE_GRAY ||
+                             color_type ==
                                  PNG_COLOR_TYPE_GRAY_ALPHA) &&
-                            (info_ptr->sig_bit.gray < info_ptr->bit_depth)) {
-                            png_set_shift (png_ptr, &(info_ptr->sig_bit));
-                            *maxvalP = (1l << info_ptr->sig_bit.gray) - 1;
+                            (sig_bit->gray < png_get_bit_depth(png_ptr, info_ptr))) {
+                            png_set_shift (png_ptr, sig_bit);
+                            *maxvalP = (1l << sig_bit->gray) - 1;
                             if (verbose)
                                 pm_message("image has fewer significant bits, "
                                            "writing file with %d bits",
-                                           info_ptr->sig_bit.gray);
+                                           sig_bit->gray);
                         }
             }
             break;
 
         case ALPHA_ONLY:
-            if ((info_ptr->color_type == PNG_COLOR_TYPE_RGB_ALPHA ||
-                 info_ptr->color_type == PNG_COLOR_TYPE_GRAY_ALPHA) && 
-                (info_ptr->sig_bit.gray < info_ptr->bit_depth)) {
-                png_set_shift (png_ptr, &(info_ptr->sig_bit));
+            if ((color_type == PNG_COLOR_TYPE_RGB_ALPHA ||
+                 color_type == PNG_COLOR_TYPE_GRAY_ALPHA) && 
+                (sig_bit->gray < png_get_bit_depth(png_ptr, info_ptr))) {
+                png_set_shift (png_ptr, sig_bit);
                 if (verbose)
                     pm_message ("image has fewer significant bits, "
                                 "writing file with %d bits", 
-                                info_ptr->sig_bit.alpha);
-                *maxvalP = (1l << info_ptr->sig_bit.alpha) - 1;
+                                sig_bit->alpha);
+                *maxvalP = (1l << sig_bit->alpha) - 1;
             }
             break;
 
@@ -739,22 +792,28 @@ setupSignificantBits(png_struct *        const png_ptr
 
 
 static bool
-imageHasColor(png_info * const info_ptr) {
+imageHasColor(png_structp const png_ptr, png_info * const info_ptr) {
 
     bool retval;
+    png_byte color_type;
+    png_colorp palette;
+    int num_palette;
 
-    if (info_ptr->color_type == PNG_COLOR_TYPE_GRAY ||
-        info_ptr->color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
+    color_type = png_get_color_type(png_ptr, info_ptr);
+    if (color_type == PNG_COLOR_TYPE_GRAY ||
+        color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
 
         retval = FALSE;
-    else if (info_ptr->color_type == PNG_COLOR_TYPE_PALETTE) {
+    else if (color_type == PNG_COLOR_TYPE_PALETTE &&
+             png_get_PLTE(png_ptr, info_ptr,
+                          &palette, &num_palette) & PNG_INFO_PLTE) {
         bool foundColor;
         unsigned int i;
             
         for (i = 0, foundColor = FALSE;
-             i < info_ptr->num_palette && !foundColor;
+             i < num_palette && !foundColor;
              ++i) {
-            if (iscolor(info_ptr->palette[i]))
+            if (iscolor(palette[i]))
                 foundColor = TRUE;
         }
         retval = foundColor;
@@ -767,14 +826,15 @@ imageHasColor(png_info * const info_ptr) {
 
 
 static void
-determineOutputType(png_info *          const info_ptr,
+determineOutputType(png_structp         const png_ptr,
+                    png_info *          const info_ptr,
                     enum alpha_handling const alphaHandling,
                     pngcolor            const bgColor,
                     xelval              const maxval,
                     int *               const pnmTypeP) {
 
     if (alphaHandling != ALPHA_ONLY &&
-        (imageHasColor(info_ptr) || !isGrayscale(bgColor)))
+        (imageHasColor(png_ptr, info_ptr) || !isGrayscale(bgColor)))
         *pnmTypeP = PPM_TYPE;
     else {
         if (maxval > 1)
@@ -787,7 +847,8 @@ determineOutputType(png_info *          const info_ptr
 
 
 static void
-getBackgroundColor(png_info *        const info_ptr,
+getBackgroundColor(png_structp       const png_ptr,
+                   png_info *        const info_ptr,
                    const char *      const requestedColor,
                    float             const totalgamma,
                    xelval            const maxval,
@@ -798,6 +859,8 @@ getBackgroundColor(png_info *        const info_ptr,
    Otherwise, if the PNG specifies a background color, that's the one.
    And otherwise, it's white.
 -----------------------------------------------------------------------------*/
+    png_color_16p background;
+
     if (requestedColor) {
         /* Background was specified from the command-line; we always
            use that.  I chose to do no gamma-correction in this case;
@@ -809,27 +872,32 @@ getBackgroundColor(png_info *        const info_ptr,
         bgColorP->g = PPM_GETG(backcolor);
         bgColorP->b = PPM_GETB(backcolor);
 
-    } else if (info_ptr->valid & PNG_INFO_bKGD) {
+    } else if (png_get_bKGD(png_ptr, info_ptr, &background) & PNG_INFO_bKGD) {
         /* didn't manage to get libpng to work (bugs?) concerning background
            processing, therefore we do our own.
         */
-        switch (info_ptr->color_type) {
+        switch (png_get_color_type(png_ptr, info_ptr)) {
         case PNG_COLOR_TYPE_GRAY:
         case PNG_COLOR_TYPE_GRAY_ALPHA:
             bgColorP->r = bgColorP->g = bgColorP->b = 
-                gamma_correct(info_ptr->background.gray, totalgamma);
+                gamma_correct(background->gray, totalgamma);
             break;
         case PNG_COLOR_TYPE_PALETTE: {
-            png_color const rawBgcolor = 
-                info_ptr->palette[info_ptr->background.index];
-            bgColorP->r = gamma_correct(rawBgcolor.red, totalgamma);
-            bgColorP->g = gamma_correct(rawBgcolor.green, totalgamma);
-            bgColorP->b = gamma_correct(rawBgcolor.blue, totalgamma);
+            png_colorp palette;
+            int num_palette;
+
+            if (png_get_PLTE(png_ptr, info_ptr,
+                             &palette, &num_palette) & PNG_INFO_PLTE) {
+                png_color const rawBgcolor = palette[background->index];
+                bgColorP->r = gamma_correct(rawBgcolor.red, totalgamma);
+                bgColorP->g = gamma_correct(rawBgcolor.green, totalgamma);
+                bgColorP->b = gamma_correct(rawBgcolor.blue, totalgamma);
+             }
         }
         break;
         case PNG_COLOR_TYPE_RGB:
         case PNG_COLOR_TYPE_RGB_ALPHA: {
-            png_color_16 const rawBgcolor = info_ptr->background;
+            png_color_16 const rawBgcolor = *background;
             
             bgColorP->r = gamma_correct(rawBgcolor.red,   totalgamma);
             bgColorP->g = gamma_correct(rawBgcolor.green, totalgamma);
@@ -848,6 +916,7 @@ static void
 writePnm(FILE *              const ofP,
          xelval              const maxval,
          int                 const pnm_type,
+         png_structp         const png_ptr, 
          png_info *          const info_ptr,
          png_byte **         const png_image,
          pngcolor            const bgColor,
@@ -865,6 +934,7 @@ writePnm(FILE *              const ofP,
 -----------------------------------------------------------------------------*/
     xel * xelrow;
     unsigned int row;
+    png_uint_32 width, height;
 
     if (verbose)
         pm_message ("writing a %s file (maxval=%u)",
@@ -874,27 +944,35 @@ writePnm(FILE *              const ofP,
                     "UNKNOWN!", 
                     maxval);
     
-    xelrow = pnm_allocrow(info_ptr->width);
+    xelrow = pnm_allocrow(png_get_image_width(png_ptr, info_ptr));
 
-    pnm_writepnminit(stdout, info_ptr->width, info_ptr->height, maxval,
-                     pnm_type, FALSE);
+    width = png_get_image_width(png_ptr, info_ptr);
+    height = png_get_image_height(png_ptr, info_ptr);
 
-    for (row = 0; row < info_ptr->height; ++row) {
+    pnm_writepnminit(stdout, width, height, maxval, pnm_type, FALSE);
+
+    for (row = 0; row < height; ++row) {
         png_byte * png_pixelP;
         int col;
 
         png_pixelP = &png_image[row][0];  /* initial value */
-        for (col = 0; col < info_ptr->width; ++col) {
-            switch (info_ptr->color_type) {
+        for (col = 0; col < width; ++col) {
+            switch (png_get_color_type(png_ptr, info_ptr)) {
             case PNG_COLOR_TYPE_GRAY: {
                 pngcolor fgColor;
+                png_color_16p trans_color;
+
                 fgColor.r = fgColor.g = fgColor.b = get_png_val(png_pixelP);
-                setXel(&xelrow[col], fgColor, bgColor, alpha_handling,
-                       ((info_ptr->valid & PNG_INFO_tRNS) &&
-                        (fgColor.r == 
-                         gamma_correct(info_ptr->trans_values.gray,
-                                       totalgamma))) ?
-                       0 : maxval);
+
+                if (png_get_tRNS(png_ptr, info_ptr,
+                                 NULL, NULL, &trans_color) & PNG_INFO_tRNS &&
+                    (fgColor.r ==  gamma_correct(trans_color->gray,
+                                                 totalgamma))) {
+                    setXel(&xelrow[col], fgColor, bgColor, alpha_handling, 0);
+                } else {
+                    setXel(&xelrow[col], fgColor, bgColor, alpha_handling,
+                           maxval);
+                }
             }
             break;
 
@@ -909,19 +987,31 @@ writePnm(FILE *              const ofP,
             break;
 
             case PNG_COLOR_TYPE_PALETTE: {
-                png_uint_16 const index        = get_png_val(png_pixelP);
-                png_color   const paletteColor = info_ptr->palette[index];
+                png_uint_16 const index = get_png_val(png_pixelP);
+                png_colorp palette;
+                int num_palette;
 
-                pngcolor fgColor;
+                if (png_get_PLTE(png_ptr, info_ptr,
+                                 &palette, &num_palette) & PNG_INFO_PLTE) {
+                    png_color const paletteColor = palette[index];
+                    pngcolor fgColor;
+                    png_bytep trans_alpha;
+                    int num_trans;
 
-                fgColor.r = paletteColor.red;
-                fgColor.g = paletteColor.green;
-                fgColor.b = paletteColor.blue;
+                    fgColor.r = paletteColor.red;
+                    fgColor.g = paletteColor.green;
+                    fgColor.b = paletteColor.blue;
 
-                setXel(&xelrow[col], fgColor, bgColor, alpha_handling,
-                       (info_ptr->valid & PNG_INFO_tRNS) &&
-                       index < info_ptr->num_trans ?
-                       info_ptr->trans[index] : maxval);
+                    if (png_get_tRNS(png_ptr, info_ptr,
+                                     &trans_alpha,
+                                     &num_trans, NULL) & PNG_INFO_tRNS) {
+                        setXel(&xelrow[col], fgColor, bgColor, alpha_handling,
+                               index < num_trans ? trans_alpha[index] : maxval);
+                     } else {
+                        setXel(&xelrow[col], fgColor, bgColor, alpha_handling,
+                               maxval);
+                     }
+                }
             }
             break;
                 
@@ -932,8 +1022,8 @@ writePnm(FILE *              const ofP,
                 fgColor.g = get_png_val(png_pixelP);
                 fgColor.b = get_png_val(png_pixelP);
                 setXel(&xelrow[col], fgColor, bgColor, alpha_handling,
-                       isTransparentColor(fgColor, info_ptr, totalgamma) ?
-                       0 : maxval);
+                       isTransparentColor(fgColor, png_ptr, info_ptr,
+                                          totalgamma) ? 0 : maxval);
             }
             break;
 
@@ -950,10 +1040,10 @@ writePnm(FILE *              const ofP,
             break;
 
             default:
-                pm_error ("unknown PNG color type: %d", info_ptr->color_type);
+                pm_error ("unknown PNG color type: %d", png_get_color_type(png_ptr, info_ptr));
             }
         }
-        pnm_writepnmrow(ofP, xelrow, info_ptr->width, maxval, pnm_type, FALSE);
+        pnm_writepnmrow(ofP, xelrow, width, maxval, pnm_type, FALSE);
     }
     pnm_freerow (xelrow);
 }
@@ -974,6 +1064,7 @@ convertpng(FILE *             const ifp, 
     int pnm_type;
     pngcolor bgColor;
     float totalgamma;
+    int res_x, res_y, unit_type;
 
     *errorlevelP = 0;
 
@@ -996,28 +1087,28 @@ convertpng(FILE *             const ifp, 
     png_set_sig_bytes (png_ptr, SIG_CHECK_SIZE);
     png_read_info (png_ptr, info_ptr);
 
-    MALLOCARRAY(png_image, info_ptr->height);
+    MALLOCARRAY(png_image, png_get_image_height(png_ptr, info_ptr));
     if (png_image == NULL) {
         png_destroy_read_struct (&png_ptr, &info_ptr, (png_infopp)NULL);
         pm_closer (ifp);
         pm_error ("couldn't allocate space for image");
     }
 
-    if (info_ptr->bit_depth == 16)
-        linesize = 2 * info_ptr->width;
+    if (png_get_bit_depth(png_ptr, info_ptr) == 16)
+        linesize = 2 * png_get_image_width(png_ptr, info_ptr);
     else
-        linesize = info_ptr->width;
+        linesize = png_get_image_width(png_ptr, info_ptr);
 
-    if (info_ptr->color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
+    if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY_ALPHA)
         linesize *= 2;
     else
-        if (info_ptr->color_type == PNG_COLOR_TYPE_RGB)
+        if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB)
             linesize *= 3;
         else
-            if (info_ptr->color_type == PNG_COLOR_TYPE_RGB_ALPHA)
+            if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB_ALPHA)
                 linesize *= 4;
 
-    for (y = 0 ; y < info_ptr->height ; y++) {
+    for (y = 0 ; y < png_get_image_height(png_ptr, info_ptr) ; y++) {
         png_image[y] = malloc (linesize);
         if (png_image[y] == NULL) {
             for (x = 0 ; x < y ; x++)
@@ -1029,7 +1120,7 @@ convertpng(FILE *             const ifp, 
         }
     }
 
-    if (info_ptr->bit_depth < 8)
+    if (png_get_bit_depth(png_ptr, info_ptr) < 8)
         png_set_packing (png_ptr);
 
     setupGammaCorrection(png_ptr, info_ptr, cmdline.gamma, &totalgamma);
@@ -1037,8 +1128,8 @@ convertpng(FILE *             const ifp, 
     setupSignificantBits(png_ptr, info_ptr, cmdline.alpha,
                          &maxval, errorlevelP);
 
-    getBackgroundColor(info_ptr, cmdline.background, totalgamma, maxval,
-                       &bgColor);
+    getBackgroundColor(png_ptr, info_ptr, cmdline.background, totalgamma,
+                       maxval, &bgColor);
 
     png_read_image (png_ptr, png_image);
     png_read_end (png_ptr, info_ptr);
@@ -1048,16 +1139,17 @@ convertpng(FILE *             const ifp, 
        completes.  That's because it comes from chunks that are at the
        end of the stream.
     */
-        dump_png_info(info_ptr);
+        dump_png_info(png_ptr, info_ptr);
 
     if (mtime)
-        show_time (info_ptr);
+        show_time (png_ptr, info_ptr);
     if (tfp)
-        save_text (info_ptr, tfp);
+        save_text (png_ptr, info_ptr, tfp);
 
-    if (info_ptr->valid & PNG_INFO_pHYs) {
+    if (png_get_pHYs(png_ptr, info_ptr,
+                     &res_x, &res_y, &unit_type) & PNG_INFO_pHYs) {
         float r;
-        r = (float)info_ptr->x_pixels_per_unit / info_ptr->y_pixels_per_unit;
+        r = (float)res_x / res_y;
         if (r != 1.0) {
             pm_message ("warning - non-square pixels; "
                         "to fix do a 'pamscale -%cscale %g'",
@@ -1067,13 +1159,13 @@ convertpng(FILE *             const ifp, 
         }
     }
 
-    determineOutputType(info_ptr, cmdline.alpha, bgColor, maxval, &pnm_type);
+    determineOutputType(png_ptr, info_ptr, cmdline.alpha, bgColor, maxval, &pnm_type);
 
-    writePnm(stdout, maxval, pnm_type, info_ptr, png_image, bgColor, 
+    writePnm(stdout, maxval, pnm_type, png_ptr, info_ptr, png_image, bgColor, 
              cmdline.alpha, totalgamma);
 
     fflush(stdout);
-    for (y = 0 ; y < info_ptr->height ; y++)
+    for (y = 0 ; y < png_get_image_height(png_ptr, info_ptr) ; y++)
         free (png_image[y]);
     free (png_image);
     png_destroy_read_struct (&png_ptr, &info_ptr, (png_infopp)NULL);
