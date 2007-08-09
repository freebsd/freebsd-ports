--- Sources/SmallJPEG/jpgd/jpegdecoder.h.orig	Wed May 30 21:51:53 2007
+++ Sources/SmallJPEG/jpgd/jpegdecoder.h	Wed May 30 21:53:54 2007
@@ -493,26 +493,26 @@
 
   void find_eoi(void);
 //------------------
-  /*inline*/ uint jpeg_decoder::rol(uint i, uchar j);
-  /*inline*/ uint jpeg_decoder::get_char(void);
-  /*inline*/ uint jpeg_decoder::get_char(bool *Ppadding_flag);
-  /*inline*/ void jpeg_decoder::stuff_char(uchar q);
-  /*inline*/ uchar jpeg_decoder::get_octet(void);
-  /*inline*/ uint jpeg_decoder::get_bits_1(int num_bits);
-  /*inline*/ uint jpeg_decoder::get_bits_2(int numbits);
-  /*inline*/ int jpeg_decoder::huff_decode(Phuff_tables_t Ph);
+  /*inline*/ uint rol(uint i, uchar j);
+  /*inline*/ uint get_char(void);
+  /*inline*/ uint get_char(bool *Ppadding_flag);
+  /*inline*/ void stuff_char(uchar q);
+  /*inline*/ uchar get_octet(void);
+  /*inline*/ uint get_bits_1(int num_bits);
+  /*inline*/ uint get_bits_2(int numbits);
+  /*inline*/ int huff_decode(Phuff_tables_t Ph);
 #ifdef SUPPORT_X86ASM
-  /*inline*/ uint jpeg_decoder::huff_extend(uint i, int c);
+  /*inline*/ uint huff_extend(uint i, int c);
 #endif
-  /*inline*/ uchar jpeg_decoder::clamp(int i);
+  /*inline*/ uchar clamp(int i);
 
 #ifdef SUPPORT_MMX
-  /*inline*/ uint jpeg_decoder::get_high_byte_mmx(void);
-  /*inline*/ uint jpeg_decoder::get_high_word_mmx(void);
-  /*inline*/ void jpeg_decoder::get_bits_2_mmx_init(void);
-  /*inline*/ void jpeg_decoder::get_bits_2_mmx_deinit(void);
-  /*inline*/ uint jpeg_decoder::get_bits_2_mmx(int numbits);
-  /*inline*/ int jpeg_decoder::huff_decode_mmx(Phuff_tables_t Ph);
+  /*inline*/ uint get_high_byte_mmx(void);
+  /*inline*/ uint get_high_word_mmx(void);
+  /*inline*/ void get_bits_2_mmx_init(void);
+  /*inline*/ void get_bits_2_mmx_deinit(void);
+  /*inline*/ uint get_bits_2_mmx(int numbits);
+  /*inline*/ int huff_decode_mmx(Phuff_tables_t Ph);
 #endif
 //------------------
   int   image_x_size;
