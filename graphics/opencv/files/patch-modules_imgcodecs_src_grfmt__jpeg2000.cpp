--- modules/imgcodecs/src/grfmt_jpeg2000.cpp.orig	2018-02-23 08:38:33 UTC
+++ modules/imgcodecs/src/grfmt_jpeg2000.cpp
@@ -337,7 +337,7 @@ bool  Jpeg2KDecoder::readComponent8u( uchar *data, voi
 
     for( y = 0; y < yend - ystart; )
     {
-        jas_seqent_t* pix_row = &jas_matrix_get( buffer, y / ystep, 0 );
+        jas_seqent_t* pix_row = jas_matrix_getref( buffer, y / ystep, 0 );
         uchar* dst = data + (y - yoffset) * step - xoffset;
 
         if( xstep == 1 )
@@ -401,7 +401,7 @@ bool  Jpeg2KDecoder::readComponent16u( unsigned short 
 
     for( y = 0; y < yend - ystart; )
     {
-        jas_seqent_t* pix_row = &jas_matrix_get( buffer, y / ystep, 0 );
+        jas_seqent_t* pix_row = jas_matrix_getref( buffer, y / ystep, 0 );
         ushort* dst = data + (y - yoffset) * step - xoffset;
 
         if( xstep == 1 )
