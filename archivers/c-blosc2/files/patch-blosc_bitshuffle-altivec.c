--- blosc/bitshuffle-altivec.c.orig	2024-08-12 12:46:55 UTC
+++ blosc/bitshuffle-altivec.c
@@ -40,15 +40,15 @@
 #include <stdio.h>
 #include <string.h>
 
-static void helper_print(__vector uint8_t v, char* txt){
+static void helper_print(__vector unsigned char v, char* txt){
   printf("%s %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",txt,
   v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8], v[9], v[10], v[11], v[12], v[13], v[14], v[15]);
 }
 #endif
 
 
-static inline __vector uint8_t gen_save_mask(size_t offset){
-  __vector uint8_t mask;
+static inline __vector unsigned char gen_save_mask(size_t offset){
+  __vector unsigned char mask;
   size_t k;
   for (k = 0; k < 16; k++)
     mask[k] = (k<offset)?0:0xFF;
@@ -57,8 +57,8 @@ static inline __vector uint8_t gen_save_mask(size_t of
 
 
 // Build and return a bit-permutation mask
-static __vector uint8_t make_bitperm_mask(int type_size, int bit) {
-  __vector uint8_t result;
+static __vector unsigned char make_bitperm_mask(int type_size, int bit) {
+  __vector unsigned char result;
   if (type_size == 1) {
     // data_type is 8 bits long
     for (int i = 0; i < 16; i++)
@@ -93,29 +93,29 @@ bitunshuffle1_altivec(void* _src, void* dest, const si
   size_t nbyte_row = size / 8;
 
   // working vectors
-  __vector uint8_t xmm0[8], xmm1[8], masks[8];
+  __vector unsigned char xmm0[8], xmm1[8], masks[8];
   // Vector masks
-  static const __vector uint8_t lo01 = (const __vector uint8_t) {
+  static const __vector unsigned char lo01 = (const __vector unsigned char) {
     0x00, 0x01, 0x04, 0x05, 0x08, 0x09, 0x0c, 0x0d,
     0x10, 0x11, 0x14, 0x15, 0x18, 0x19, 0x1c, 0x1d};
-  static const __vector uint8_t hi01 = (const __vector uint8_t) {
+  static const __vector unsigned char hi01 = (const __vector unsigned char) {
     0x02, 0x03, 0x06, 0x07, 0x0a, 0x0b, 0x0e, 0x0f,
     0x12, 0x13, 0x16, 0x17, 0x1a, 0x1b, 0x1e, 0x1f};
-  static const __vector uint8_t lo02 = (const __vector uint8_t) {
+  static const __vector unsigned char lo02 = (const __vector unsigned char) {
     0x00, 0x01, 0x08, 0x09, 0x10, 0x11, 0x18, 0x19,
     0x02, 0x03, 0x0a, 0x0b, 0x12, 0x13, 0x1a, 0x1b};
-  static const __vector uint8_t hi02 = (const __vector uint8_t) {
+  static const __vector unsigned char hi02 = (const __vector unsigned char) {
     0x04, 0x05, 0x0c, 0x0d, 0x14, 0x15, 0x1c, 0x1d,
     0x06, 0x07, 0x0e, 0x0f, 0x16, 0x17, 0x1e, 0x1f};
-  static const __vector uint8_t epi64_low = (const __vector uint8_t) {
+  static const __vector unsigned char epi64_low = (const __vector unsigned char) {
     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17};
-  static const __vector uint8_t epi64_hi = (const __vector uint8_t) {
+  static const __vector unsigned char epi64_hi = (const __vector unsigned char) {
     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f};
 
   for (kk = 0; kk < 8; kk++){
-    __vector uint8_t msk;
+    __vector unsigned char msk;
     for (ii = 0; ii < 8; ii++){
       msk[ii] = 127-(16*ii+2*kk);
       msk[ii+8] = 127-(16*ii+2*kk+1);
@@ -164,13 +164,13 @@ bitunshuffle1_altivec(void* _src, void* dest, const si
 
       // At this stage each vector xmm1 contains the data from 16 adjacent bytes
       for (int ll = 0; ll < 8; ll++){
-        __vector uint8_t xmm = xmm1[ll];
+        __vector unsigned char xmm = xmm1[ll];
         //helper_print(xmm, "vector transposed");
         for (kk = 0; kk < 8; kk++) {
-           __vector uint16_t tmp;
-           tmp = (__vector uint16_t) vec_bperm(xmm, masks[kk]);
+           __vector unsigned short tmp;
+           tmp = (__vector unsigned short) vec_bperm(xmm, masks[kk]);
            //printf("%d %d\n", vp, tmp[4]);
-           //helper_print((__vector uint8_t)tmp, "tmp");
+           //helper_print((__vector unsigned char)tmp, "tmp");
            out_s[vp++] = tmp[4];
         }
       }
@@ -182,7 +182,7 @@ int64_t bshuf_trans_byte_elem_16(const void* in, void*
 /* Transpose bytes within elements for 16 bit elements. */
 int64_t bshuf_trans_byte_elem_16(const void* in, void* out, const size_t size) {
   static const uint8_t bytesoftype = 2;
-  __vector uint8_t xmm0[2];
+  __vector unsigned char xmm0[2];
 
   for (size_t i = 0; i + 15 < size; i += 16) {
     for (int j = 0; j < bytesoftype; j++)
@@ -202,7 +202,7 @@ int64_t bshuf_trans_byte_elem_32(const void* in, void*
 /* Transpose bytes within elements for 32 bit elements. */
 int64_t bshuf_trans_byte_elem_32(const void* in, void* out, const size_t size) {
   static const uint8_t bytesoftype = 4;
-  __vector uint8_t xmm0[4];
+  __vector unsigned char xmm0[4];
 
   for (size_t i = 0; i + 15 < size; i += 16) {
     for (int j = 0; j < bytesoftype; j++)
@@ -222,7 +222,7 @@ int64_t bshuf_trans_byte_elem_64(const void* in, void*
 /* Transpose bytes within elements for 64 bit elements. */
 int64_t bshuf_trans_byte_elem_64(const void* in, void* out, const size_t size) {
   static const uint8_t bytesoftype = 8;
-  __vector uint8_t xmm0[8];
+  __vector unsigned char xmm0[8];
 
   for (size_t i = 0; i + 15 < size; i += 16) {
     for (int j = 0; j < bytesoftype; j++)
@@ -242,7 +242,7 @@ int64_t bshuf_trans_byte_elem_128(const void* in, void
 /* Transpose bytes within elements for 128 bit elements. */
 int64_t bshuf_trans_byte_elem_128(const void* in, void* out, const size_t size) {
   static const uint8_t bytesoftype = 16;
-  __vector uint8_t xmm0[16];
+  __vector unsigned char xmm0[16];
 
   for (size_t i = 0; i + 15 < size; i += 16) {
     for (int j = 0; j < bytesoftype; j++)
@@ -297,7 +297,7 @@ int64_t bshuf_trans_byte_elem_altivec(const void* in, 
 
     if ((elem_size % 16) == 0) {
       nchunk_elem = elem_size / 16;
-      TRANS_ELEM_TYPE(in, out, size, nchunk_elem, __vector uint8_t);
+      TRANS_ELEM_TYPE(in, out, size, nchunk_elem, __vector unsigned char);
       count = bshuf_trans_byte_elem_128(out, tmp_buf,
                                         size * nchunk_elem);
       bshuf_trans_elem(tmp_buf, out, 16, nchunk_elem, size);
@@ -334,7 +334,7 @@ int64_t bshuf_trans_bit_byte_altivec(const void* in, v
   uint8_t* out_b = (uint8_t*)out;
   int64_t count;
   size_t nbyte = elem_size * size;
-  __vector uint8_t data, masks[8];
+  __vector unsigned char data, masks[8];
   size_t ii, kk;
 
   CHECK_MULT_EIGHT(nbyte);
@@ -347,9 +347,9 @@ int64_t bshuf_trans_bit_byte_altivec(const void* in, v
   for (ii = 0; ii + 15 < nbyte; ii += 16) {
     data = vec_xl(ii, in_b);
     for (kk = 0; kk < 8; kk++) {
-      __vector uint16_t tmp;
+      __vector unsigned short tmp;
       uint16_t* oui16;
-      tmp = (__vector uint16_t) vec_bperm(data, masks[kk]);
+      tmp = (__vector unsigned short) vec_bperm(data, masks[kk]);
       oui16 = (uint16_t*)&out_b[(ii + kk*nbyte) >> 3];
       *oui16 = tmp[4];
     }
@@ -387,28 +387,28 @@ int64_t bshuf_trans_byte_bitrow_altivec(const void* in
  * the bytes. */
 int64_t bshuf_trans_byte_bitrow_altivec(const void* in, void* out, const size_t size,
                                         const size_t elem_size) {
-  static const __vector uint8_t epi8_low = (const __vector uint8_t) {
+  static const __vector unsigned char epi8_low = (const __vector unsigned char) {
     0x00, 0x10, 0x01, 0x11, 0x02, 0x12, 0x03, 0x13,
     0x04, 0x14, 0x05, 0x15, 0x06, 0x16, 0x07, 0x17};
-  static const __vector uint8_t epi8_hi = (const __vector uint8_t) {
+  static const __vector unsigned char epi8_hi = (const __vector unsigned char) {
     0x08, 0x18, 0x09, 0x19, 0x0a, 0x1a, 0x0b, 0x1b,
     0x0c, 0x1c, 0x0d, 0x1d, 0x0e, 0x1e, 0x0f, 0x1f};
-  static const __vector uint8_t epi16_low = (const __vector uint8_t) {
+  static const __vector unsigned char epi16_low = (const __vector unsigned char) {
     0x00, 0x01, 0x10, 0x11, 0x02, 0x03, 0x12, 0x13,
     0x04, 0x05, 0x14, 0x15, 0x06, 0x07, 0x16, 0x17};
-  static const __vector uint8_t epi16_hi = (const __vector uint8_t) {
+  static const __vector unsigned char epi16_hi = (const __vector unsigned char) {
     0x08, 0x09, 0x18, 0x19, 0x0a, 0x0b, 0x1a, 0x1b,
     0x0c, 0x0d, 0x1c, 0x1d, 0x0e, 0x0f, 0x1e, 0x1f};
-  static const __vector uint8_t epi32_low = (const __vector uint8_t) {
+  static const __vector unsigned char epi32_low = (const __vector unsigned char) {
     0x00, 0x01, 0x02, 0x03, 0x10, 0x11, 0x12, 0x13,
     0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17};
-  static const __vector uint8_t epi32_hi = (const __vector uint8_t) {
+  static const __vector unsigned char epi32_hi = (const __vector unsigned char) {
     0x08, 0x09, 0x0a, 0x0b, 0x18, 0x19, 0x1a, 0x1b,
     0x0c, 0x0d, 0x0e, 0x0f, 0x1c, 0x1d, 0x1e, 0x1f};
-  static const __vector uint8_t epi64_low = (const __vector uint8_t) {
+  static const __vector unsigned char epi64_low = (const __vector unsigned char) {
     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17};
-  static const __vector uint8_t epi64_hi = (const __vector uint8_t) {
+  static const __vector unsigned char epi64_hi = (const __vector unsigned char) {
     0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
     0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f};
 
@@ -416,7 +416,7 @@ int64_t bshuf_trans_byte_bitrow_altivec(const void* in
   uint8_t* out_b = (uint8_t*)out;
   size_t nrows = 8 * elem_size;
   size_t nbyte_row = size / 8;
-  __vector uint8_t xmm0[16], xmm1[16];
+  __vector unsigned char xmm0[16], xmm1[16];
 
   CHECK_MULT_EIGHT(size);
 
@@ -543,7 +543,7 @@ int64_t bshuf_shuffle_bit_eightelem_altivec(const void
   const uint8_t* in_b = (const uint8_t*)in;
   uint8_t* out_b = (uint8_t*)out;
   size_t nbyte = elem_size * size;
-  __vector uint8_t masks[8], data;
+  __vector unsigned char masks[8], data;
 
   CHECK_MULT_EIGHT(size);
 
@@ -560,9 +560,9 @@ int64_t bshuf_shuffle_bit_eightelem_altivec(const void
       for (size_t jj = 0; jj + 15 < 8 * elem_size; jj += 16) {
         data = vec_xl(ii + jj, in_b);
         for (size_t kk = 0; kk < 8; kk++) {
-          __vector uint16_t tmp;
+          __vector unsigned short tmp;
           uint16_t* oui16;
-          tmp = (__vector uint16_t) vec_bperm(data, masks[kk]);
+          tmp = (__vector unsigned short) vec_bperm(data, masks[kk]);
           oui16 = (uint16_t*)&out_b[ii + (jj>>3) + kk * elem_size];
           *oui16 = tmp[4];
         }
