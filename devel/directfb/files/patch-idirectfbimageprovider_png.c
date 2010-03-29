--- interfaces/IDirectFBImageProvider/idirectfbimageprovider_png.c.orig	2007-12-15 13:30:24.000000000 +0100
+++ interfaces/IDirectFBImageProvider/idirectfbimageprovider_png.c	2010-03-29 21:00:24.000000000 +0200
@@ -168,7 +168,7 @@
 static DFBResult
 Probe( IDirectFBImageProvider_ProbeContext *ctx )
 {
-     if (png_check_sig( ctx->header, 8 ))
+     if (!png_sig_cmp( ctx->header, 0, 8 ))
           return DFB_OK;
 
      return DFB_UNSUPPORTED;
@@ -636,7 +636,7 @@
           if (data->color_type == PNG_COLOR_TYPE_PALETTE) {
                u32        key;
                png_colorp palette    = data->info_ptr->palette;
-               png_bytep  trans      = data->info_ptr->trans;
+               png_bytep  trans      = data->info_ptr->trans_alpha;
                int        num_colors = MIN( MAXCOLORMAPSIZE,
                                             data->info_ptr->num_palette );
                u8         cmap[3][num_colors];
@@ -661,7 +661,7 @@
           }
           else {
                /* ...or based on trans rgb value */
-               png_color_16p trans = &data->info_ptr->trans_values;
+               png_color_16p trans = &data->info_ptr->trans_color;
 
                data->color_key = (((trans->red & 0xff00) << 8) |
                                   ((trans->green & 0xff00)) |
@@ -672,7 +672,7 @@
      switch (data->color_type) {
           case PNG_COLOR_TYPE_PALETTE: {
                png_colorp palette    = data->info_ptr->palette;
-               png_bytep  trans      = data->info_ptr->trans;
+               png_bytep  trans      = data->info_ptr->trans_alpha;
                int        num_trans  = data->info_ptr->num_trans;
                int        num_colors = MIN( MAXCOLORMAPSIZE, data->info_ptr->num_palette );
 
