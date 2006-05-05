--- ./gl_image.c.orig	Thu May 19 17:56:13 2005
+++ ./gl_image.c	Sun Feb 26 11:23:56 2006
@@ -555,7 +555,7 @@
     size_t Pos;
 } TPngFileBuffer;
 
-void __cdecl PngReadFunc(png_struct *Png, png_bytep buf, png_size_t size)
+void PngReadFunc(png_struct *Png, png_bytep buf, png_size_t size)
 {
     TPngFileBuffer *PngFileBuffer=(TPngFileBuffer*)png_get_io_ptr(Png);
     memcpy(buf,PngFileBuffer->Buffer+PngFileBuffer->Pos,size);
@@ -1007,17 +1007,17 @@
 =================================================================
 */
 
-void __cdecl jpg_null(j_decompress_ptr cinfo)
+void jpg_null(j_decompress_ptr cinfo)
 {
 }
 
-unsigned char __cdecl jpg_fill_input_buffer(j_decompress_ptr cinfo)
+unsigned char jpg_fill_input_buffer(j_decompress_ptr cinfo)
 {
     ri.Con_Printf(PRINT_ALL, "Premature end of JPEG data\n");
     return 1;
 }
 
-void __cdecl jpg_skip_input_data(j_decompress_ptr cinfo, long num_bytes)
+void jpg_skip_input_data(j_decompress_ptr cinfo, long num_bytes)
 {
         
     cinfo->src->next_input_byte += (size_t) num_bytes;
