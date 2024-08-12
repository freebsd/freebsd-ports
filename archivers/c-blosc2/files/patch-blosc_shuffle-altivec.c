--- blosc/shuffle-altivec.c.orig	2024-08-12 12:43:11 UTC
+++ blosc/shuffle-altivec.c
@@ -27,7 +27,7 @@ shuffle2_altivec(uint8_t* const dest, const uint8_t* c
                  const int32_t vectorizable_elements, const int32_t total_elements){
   static const int32_t bytesoftype = 2;
   uint32_t i, j;
-  __vector uint8_t xmm0[2];
+  __vector unsigned char xmm0[2];
 
   for (j = 0; j < vectorizable_elements; j += 16){
     /* Fetch 16 elements (32 bytes) */
@@ -49,7 +49,7 @@ shuffle4_altivec(uint8_t* const dest, const uint8_t* c
                  const int32_t vectorizable_elements, const int32_t total_elements){
   static const int32_t bytesoftype = 4;
   int32_t i, j;
-  __vector uint8_t xmm0[4];
+  __vector unsigned char xmm0[4];
 
   for (j = 0; j < vectorizable_elements; j += 16)
   {
@@ -75,7 +75,7 @@ shuffle8_altivec(uint8_t* const dest, const uint8_t* c
                  const int32_t vectorizable_elements, const int32_t total_elements) {
   static const uint8_t bytesoftype = 8;
   int32_t i, j;
-  __vector uint8_t xmm0[8];
+  __vector unsigned char xmm0[8];
 
   for (j = 0; j < vectorizable_elements; j += 16)
   {
@@ -98,7 +98,7 @@ shuffle16_altivec(uint8_t* const dest, const uint8_t* 
                   const int32_t vectorizable_elements, const int32_t total_elements) {
   static const int32_t bytesoftype = 16;
   int32_t i, j;
-  __vector uint8_t xmm0[16];
+  __vector unsigned char xmm0[16];
 
   for (j = 0; j < vectorizable_elements; j += 16)
   {
@@ -123,7 +123,7 @@ shuffle16_tiled_altivec(uint8_t* const dest, const uin
                         const int32_t bytesoftype) {
   int32_t j, k;
   const int32_t vecs_per_el_rem = bytesoftype & 0xF;
-  __vector uint8_t xmm[16];
+  __vector unsigned char xmm[16];
 
   for (j = 0; j < vectorizable_elements; j += 16) {
     /* Advance the offset into the type by the vector size (in bytes), unless this is
@@ -154,7 +154,7 @@ unshuffle2_altivec(uint8_t* const dest, const uint8_t*
                    const int32_t vectorizable_elements, const int32_t total_elements) {
   static const int32_t bytesoftype = 2;
   uint32_t i, j;
-  __vector uint8_t xmm0[2], xmm1[2];
+  __vector unsigned char xmm0[2], xmm1[2];
 
   for (j = 0; j < vectorizable_elements; j += 16) {
     /* Load 16 elements (32 bytes) into 2 vectors registers. */
@@ -178,7 +178,7 @@ unshuffle4_altivec(uint8_t* const dest, const uint8_t*
                    const int32_t vectorizable_elements, const int32_t total_elements) {
   static const int32_t bytesoftype = 4;
   uint32_t i, j;
-  __vector uint8_t xmm0[4], xmm1[4];
+  __vector unsigned char xmm0[4], xmm1[4];
 
   for (j = 0; j < vectorizable_elements; j += 16) {
     /* Load 16 elements (64 bytes) into 4 vectors registers. */
@@ -193,11 +193,11 @@ unshuffle4_altivec(uint8_t* const dest, const uint8_t*
     /* Shuffle 2-byte words */
     for (i = 0; i < 2; i++) {
       /* Compute the low 32 bytes */
-      xmm0[i] = (__vector uint8_t) vec_vmrghh((__vector uint16_t)xmm1[i * 2],
-                                              (__vector uint16_t) xmm1[i * 2 + 1]);
+      xmm0[i] = (__vector unsigned char) vec_vmrghh((__vector unsigned short)xmm1[i * 2],
+                                              (__vector unsigned short) xmm1[i * 2 + 1]);
       /* Compute the hi 32 bytes */
-      xmm0[i+2] = (__vector uint8_t) vec_vmrglh((__vector uint16_t)xmm1[i * 2],
-                                                (__vector uint16_t)xmm1[i * 2 + 1]);
+      xmm0[i+2] = (__vector unsigned char) vec_vmrglh((__vector unsigned short)xmm1[i * 2],
+                                                (__vector unsigned short)xmm1[i * 2 + 1]);
     }
     /* Store the result vectors in proper order */
     vec_xst(xmm0[0], bytesoftype * j, dest);
@@ -213,7 +213,7 @@ unshuffle8_altivec(uint8_t* const dest, const uint8_t*
                    const int32_t vectorizable_elements, const int32_t total_elements) {
   static const uint8_t bytesoftype = 8;
   uint32_t i, j;
-  __vector uint8_t xmm0[8], xmm1[8];
+  __vector unsigned char xmm0[8], xmm1[8];
 
   // Initialize permutations for writing
   for (j = 0; j < vectorizable_elements; j += 16) {
@@ -227,17 +227,17 @@ unshuffle8_altivec(uint8_t* const dest, const uint8_t*
     }
     /* Shuffle 2-byte words */
     for (i = 0; i < 4; i++) {
-      xmm0[i] = (__vector uint8_t)vec_vmrghh((__vector uint16_t)xmm1[i * 2],
-                                             (__vector uint16_t)xmm1[i * 2 + 1]);
-      xmm0[4 + i] = (__vector uint8_t)vec_vmrglh((__vector uint16_t)xmm1[i * 2],
-                                                 (__vector uint16_t)xmm1[i * 2 + 1]);
+      xmm0[i] = (__vector unsigned char)vec_vmrghh((__vector unsigned short)xmm1[i * 2],
+                                             (__vector unsigned short)xmm1[i * 2 + 1]);
+      xmm0[4 + i] = (__vector unsigned char)vec_vmrglh((__vector unsigned short)xmm1[i * 2],
+                                                 (__vector unsigned short)xmm1[i * 2 + 1]);
     }
     /* Shuffle 4-byte dwords */
     for (i = 0; i < 4; i++) {
-      xmm1[i] = (__vector uint8_t)vec_vmrghw((__vector uint32_t)xmm0[i * 2],
-                                             (__vector uint32_t)xmm0[i * 2 + 1]);
-      xmm1[4 + i] = (__vector uint8_t)vec_vmrglw((__vector uint32_t)xmm0[i * 2],
-                                                 (__vector uint32_t)xmm0[i * 2 + 1]);
+      xmm1[i] = (__vector unsigned char)vec_vmrghw((__vector unsigned int)xmm0[i * 2],
+                                             (__vector unsigned int)xmm0[i * 2 + 1]);
+      xmm1[4 + i] = (__vector unsigned char)vec_vmrglw((__vector unsigned int)xmm0[i * 2],
+                                                 (__vector unsigned int)xmm0[i * 2 + 1]);
     }
     /* Store the result vectors in proper order */
     vec_xst(xmm1[0], bytesoftype * j, dest);
@@ -258,7 +258,7 @@ unshuffle16_altivec(uint8_t* const dest, const uint8_t
                     const int32_t vectorizable_elements, const int32_t total_elements) {
   static const int32_t bytesoftype = 16;
   uint32_t i, j;
-  __vector uint8_t xmm0[16];
+  __vector unsigned char xmm0[16];
 
   for (j = 0; j < vectorizable_elements; j += 16) {
     /* Load 16 elements (64 bytes) into 4 vectors registers. */
@@ -282,7 +282,7 @@ unshuffle16_tiled_altivec(uint8_t* const dest, const u
                           const int32_t bytesoftype) {
   int32_t i, j, offset_into_type;
   const int32_t vecs_per_el_rem = bytesoftype &  0xF;
-  __vector uint8_t xmm[16];
+  __vector unsigned char xmm[16];
 
 
   /* Advance the offset into the type by the vector size (in bytes), unless this is
