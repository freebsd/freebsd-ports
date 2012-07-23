--- ./src/vigra_impex/png.cxx.orig	2009-12-20 17:32:28.000000000 +0200
+++ ./src/vigra_impex/png.cxx	2012-07-23 14:20:14.000000000 +0300
@@ -81,7 +81,7 @@
 static void PngError( png_structp png_ptr, png_const_charp error_msg )
 {
     png_error_message = std::string(error_msg);
-    longjmp( png_ptr->jmpbuf, 1 );
+    longjmp( png_jmpbuf(png_ptr), 1 );
 }
 
 // called on non-fatal errors
@@ -213,7 +213,7 @@
         vigra_postcondition( png != 0, "could not create the read struct." );
 
         // create info struct
-        if (setjmp(png->jmpbuf)) {
+        if (setjmp(png_jmpbuf(png))) {
             png_destroy_read_struct( &png, &info, NULL );
             vigra_postcondition( false, png_error_message.insert(0, "error in png_create_info_struct(): ").c_str() );
         }
@@ -221,14 +221,14 @@
         vigra_postcondition( info != 0, "could not create the info struct." );
 
         // init png i/o
-        if (setjmp(png->jmpbuf)) {
+        if (setjmp(png_jmpbuf(png))) {
             png_destroy_read_struct( &png, &info, NULL );
             vigra_postcondition( false, png_error_message.insert(0, "error in png_init_io(): ").c_str() );
         }
         png_init_io( png, file.get() );
 
         // specify that the signature was already read
-        if (setjmp(png->jmpbuf)) {
+        if (setjmp(png_jmpbuf(png))) {
             png_destroy_read_struct( &png, &info, NULL );
             vigra_postcondition( false, png_error_message.insert(0, "error in png_set_sig_bytes(): ").c_str() );
         }
@@ -244,13 +244,13 @@
     void PngDecoderImpl::init()
     {
         // read all chunks up to the image data
-        if (setjmp(png->jmpbuf))
+        if (setjmp(png_jmpbuf(png)))
             vigra_postcondition( false, png_error_message.insert(0, "error in png_read_info(): ").c_str() );
         png_read_info( png, info );
 
         // pull over the header fields
         int interlace_method, compression_method, filter_method;
-        if (setjmp(png->jmpbuf))
+        if (setjmp(png_jmpbuf(png)))
             vigra_postcondition( false, png_error_message.insert(0, "error in png_get_IHDR(): ").c_str() );
         png_get_IHDR( png, info, &width, &height, &bit_depth, &color_type,
                       &interlace_method, &compression_method, &filter_method );
@@ -264,7 +264,7 @@
 
         // transform palette to rgb
         if ( color_type == PNG_COLOR_TYPE_PALETTE) {
-            if (setjmp(png->jmpbuf))
+            if (setjmp(png_jmpbuf(png)))
                 vigra_postcondition( false, png_error_message.insert(0, "error in png_palette_to_rgb(): ").c_str() );
             png_set_palette_to_rgb(png);
             color_type = PNG_COLOR_TYPE_RGB;
@@ -273,9 +273,9 @@
 
         // expand gray values to at least one byte size
         if ( color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8 ) {
-            if (setjmp(png->jmpbuf))
+            if (setjmp(png_jmpbuf(png)))
                 vigra_postcondition( false,png_error_message.insert(0, "error in png_set_gray_1_2_4_to_8(): ").c_str());
-            png_set_gray_1_2_4_to_8(png);
+            png_set_expand_gray_1_2_4_to_8(png);
             bit_depth = 8;
         }
 
@@ -283,7 +283,7 @@
 #if 0
         // strip alpha channel
         if ( color_type & PNG_COLOR_MASK_ALPHA ) {
-            if (setjmp(png->jmpbuf))
+            if (setjmp(png_jmpbuf(png)))
                 vigra_postcondition( false, png_error_message.insert(0, "error in png_set_strip_alpha(): ").c_str() );
             png_set_strip_alpha(png);
             color_type ^= PNG_COLOR_MASK_ALPHA;
@@ -325,12 +325,9 @@
 #if (PNG_LIBPNG_VER > 10008) && defined(PNG_READ_iCCP_SUPPORTED)
         char * dummyName;
         int dummyCompType;
-        char * profilePtr;
-        png_uint_32 profileLen;
-        if (info->valid & PNG_INFO_iCCP) {
-            png_get_iCCP(png, info, &dummyName, &dummyCompType, &profilePtr, &profileLen) ;
-            iccProfilePtr = (unsigned char *) profilePtr;
-            iccProfileLength = profileLen;
+        if (png_get_valid(png, info, PNG_INFO_iCCP)) {
+            png_get_iCCP(png, info, &dummyName, &dummyCompType,
+                         (unsigned char **) &iccProfilePtr, &iccProfileLength) ;
         }
 #endif
 
@@ -340,7 +337,7 @@
         // image gamma
         double image_gamma = 0.45455;
         if ( png_get_valid( png, info, PNG_INFO_gAMA ) ) {
-            if (setjmp(png->jmpbuf))
+            if (setjmp(png_jmpbuf(png)))
                 vigra_postcondition( false, png_error_message.insert(0, "error in png_get_gAMA(): ").c_str() );
             png_get_gAMA( png, info, &image_gamma );
         }
@@ -349,26 +346,26 @@
         double screen_gamma = 2.2;
 
         // set gamma correction
-        if (setjmp(png->jmpbuf))
+        if (setjmp(png_jmpbuf(png)))
             vigra_postcondition( false, png_error_message.insert(0, "error in png_set_gamma(): ").c_str() );
         png_set_gamma( png, screen_gamma, image_gamma );
 #endif
 
         // interlace handling, get number of read passes needed
-        if (setjmp(png->jmpbuf))
+        if (setjmp(png_jmpbuf(png)))
             vigra_postcondition( false,png_error_message.insert(0, "error in png_set_interlace_handling(): ").c_str());
         n_interlace_passes = png_set_interlace_handling(png);
 
         // update png library state to reflect any changes that were made
-        if (setjmp(png->jmpbuf))
+        if (setjmp(png_jmpbuf(png)))
             vigra_postcondition( false, png_error_message.insert(0, "error in png_read_update_info(): ").c_str() );
         png_read_update_info( png, info );
 
-        if (setjmp(png->jmpbuf))
+        if (setjmp(png_jmpbuf(png)))
             vigra_postcondition( false,png_error_message.insert(0, "error in png_get_channels(): ").c_str());
         n_channels = png_get_channels(png, info);
 
-        if (setjmp(png->jmpbuf))
+        if (setjmp(png_jmpbuf(png)))
             vigra_postcondition( false,png_error_message.insert(0, "error in png_get_rowbytes(): ").c_str());
         rowsize = png_get_rowbytes(png, info);
 
@@ -379,7 +376,7 @@
     void PngDecoderImpl::nextScanline()
     {
         for (int i=0; i < n_interlace_passes; i++) {
-        if (setjmp(png->jmpbuf))
+        if (setjmp(png_jmpbuf(png)))
                 vigra_postcondition( false,png_error_message.insert(0, "error in png_read_row(): ").c_str());
             png_read_row(png, row_data.begin(), NULL);
         }
@@ -545,7 +542,7 @@
         vigra_postcondition( png != 0, "could not create the write struct." );
 
         // create info struct
-        if (setjmp(png->jmpbuf)) {
+        if (setjmp(png_jmpbuf(png))) {
             png_destroy_write_struct( &png, &info );
             vigra_postcondition( false, png_error_message.insert(0, "error in png_info_struct(): ").c_str() );
         }
@@ -556,7 +553,7 @@
         }
 
         // init png i/o
-        if (setjmp(png->jmpbuf)) {
+        if (setjmp(png_jmpbuf(png))) {
             png_destroy_write_struct( &png, &info );
             vigra_postcondition( false, png_error_message.insert(0, "error in png_init_io(): ").c_str() );
         }
@@ -571,7 +568,7 @@
     void PngEncoderImpl::finalize()
     {
         // write the IHDR
-        if (setjmp(png->jmpbuf))
+        if (setjmp(png_jmpbuf(png)))
             vigra_postcondition( false, png_error_message.insert(0, "error in png_set_IHDR(): ").c_str() );
         png_set_IHDR( png, info, width, height, bit_depth, color_type,
                       PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT,
@@ -579,7 +576,7 @@
 
         // set resolution
         if (x_resolution > 0 && y_resolution > 0) {
-            if (setjmp(png->jmpbuf))
+            if (setjmp(png_jmpbuf(png)))
                 vigra_postcondition( false, png_error_message.insert(0, "error in png_set_pHYs(): ").c_str() );
             png_set_pHYs(png, info, (png_uint_32) (x_resolution / 0.0254 + 0.5),
                          (png_uint_32) (y_resolution / 0.0254 + 0.5),
@@ -588,7 +585,7 @@
 
         // set offset
         if (position.x > 0 && position.y > 0) {
-            if (setjmp(png->jmpbuf))
+            if (setjmp(png_jmpbuf(png)))
                 vigra_postcondition( false, png_error_message.insert(0, "error in png_set_oFFs(): ").c_str() );
             png_set_oFFs(png, info, position.x, position.y, PNG_OFFSET_PIXEL);
         }
@@ -597,12 +594,12 @@
         // set icc profile
         if (iccProfile.size() > 0) {
             png_set_iCCP(png, info, "icc", 0,
-                         (char *)iccProfile.begin(), iccProfile.size());
+                         (png_const_bytep)iccProfile.begin(), iccProfile.size());
         }
 #endif
 
         // write the info struct
-        if (setjmp(png->jmpbuf))
+        if (setjmp(png_jmpbuf(png)))
             vigra_postcondition( false, png_error_message.insert(0, "error in png_write_info(): ").c_str() );
         png_write_info( png, info );
 
@@ -634,10 +631,10 @@
         }
 
         // write the whole image
-        if (setjmp(png->jmpbuf))
+        if (setjmp(png_jmpbuf(png)))
             vigra_postcondition( false, png_error_message.insert(0, "error in png_write_image(): ").c_str() );
         png_write_image( png, row_pointers.begin() );
-        if (setjmp(png->jmpbuf))
+        if (setjmp(png_jmpbuf(png)))
             vigra_postcondition( false, png_error_message.insert(0, "error in png_write_end(): ").c_str() );
         png_write_end(png, info);
     }
