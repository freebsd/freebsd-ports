--- blosc/transpose-altivec.h.orig	2024-08-12 12:42:34 UTC
+++ blosc/transpose-altivec.h
@@ -15,18 +15,18 @@
 
 #include <stdint.h>
 
-static const __vector uint8_t even = (const __vector uint8_t) {
+static const __vector unsigned char even = (const __vector unsigned char) {
   0x00, 0x02, 0x04, 0x06, 0x08, 0x0a, 0x0c, 0x0e,
   0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e};
 
-static const __vector uint8_t odd = (const __vector uint8_t) {
+static const __vector unsigned char odd = (const __vector unsigned char) {
   0x01, 0x03, 0x05, 0x07, 0x09, 0x0b, 0x0d, 0x0f,
   0x11, 0x13, 0x15, 0x17, 0x19, 0x1b, 0x1d, 0x1f};
 
 
 /* Transpose inplace 2 vectors of 16 bytes in src into dst. */
-static void transpose2x16(__vector uint8_t *xmm0) {
-  __vector uint8_t xmm1[2];
+static void transpose2x16(__vector unsigned char *xmm0) {
+  __vector unsigned char xmm1[2];
   xmm1[0] = vec_perm(xmm0[0], xmm0[1], even);
   xmm1[1] = vec_perm(xmm0[0], xmm0[1], odd);
 
@@ -38,8 +38,8 @@ static void transpose2x16(__vector uint8_t *xmm0) {
 
 /* Transpose inplace 4 vectors of 16 bytes in src into dst.
  * Total cost: 8 calls to vec_perm. */
-static void transpose4x16(__vector uint8_t *xmm0) {
-  __vector uint8_t xmm1[4];
+static void transpose4x16(__vector unsigned char *xmm0) {
+  __vector unsigned char xmm1[4];
 
   /* Transpose vectors 0-1*/
   xmm1[0] = vec_perm(xmm0[0], xmm0[1], even);
@@ -56,8 +56,8 @@ static void transpose4x16(__vector uint8_t *xmm0) {
 
 /* Transpose inplace 8 vectors of 16 bytes in src into dst.
  * Total cost: 24 calls to vec_perm. */
-static void transpose8x16(__vector uint8_t *xmm0) {
-  __vector uint8_t xmm1[8];
+static void transpose8x16(__vector unsigned char *xmm0) {
+  __vector unsigned char xmm1[8];
 
   /* Transpose vectors 0-1*/
   for (int i = 0; i < 8; i += 2){
@@ -85,8 +85,8 @@ static void transpose8x16(__vector uint8_t *xmm0) {
 
 /* Transpose inplace 16 vectors of 16 bytes in src into dst.
  * Total cost: 64 calls to vec_perm. */
-static void transpose16x16(__vector uint8_t * xmm0){
-  __vector uint8_t xmm1[16];
+static void transpose16x16(__vector unsigned char * xmm0){
+  __vector unsigned char xmm1[16];
   /* Transpose vectors 0-1*/
   for (int i = 0; i < 16; i += 2){
     xmm1[i] = vec_perm(xmm0[i], xmm0[i+1], even);
