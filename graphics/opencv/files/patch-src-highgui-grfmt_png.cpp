--- src/highgui/grfmt_png.cpp.orig     2009-10-01 03:20:58.000000000 +0300
+++ src/highgui/grfmt_png.cpp  2010-03-29 19:24:40.000000000 +0300
@@ -138,7 +138,8 @@

         if( info_ptr && end_info )
         {
-            if( setjmp( png_ptr->jmpbuf ) == 0 )
+
+  if ( (setjmp(png_jmpbuf(png_ptr))) == 0 )
             {
                 if( !m_buf.empty() )
                     png_set_read_fn(png_ptr, this, (png_rw_ptr)readDataFromBuf );
@@ -200,7 +201,7 @@
         png_infop info_ptr = (png_infop)m_info_ptr;
         png_infop end_info = (png_infop)m_end_info;

-        if( setjmp(png_ptr->jmpbuf) == 0 )
+if ( (setjmp(png_jmpbuf(png_ptr))) == 0 )
         {
             int y;

@@ -223,7 +224,7 @@
                 png_set_palette_to_rgb( png_ptr );

             if( m_color_type == PNG_COLOR_TYPE_GRAY && m_bit_depth < 8 )
-                png_set_gray_1_2_4_to_8( png_ptr );
+                 png_set_expand_gray_1_2_4_to_8( png_ptr );

             if( CV_MAT_CN(m_type) > 1 && color )
                 png_set_bgr( png_ptr ); // convert RGB to BGR
@@ -322,7 +323,8 @@

         if( info_ptr )
         {
-            if( setjmp( png_ptr->jmpbuf ) == 0 )
+
+if ( (setjmp(png_jmpbuf(png_ptr))) == 0 )
             {
                 if( m_buf )
                 {
