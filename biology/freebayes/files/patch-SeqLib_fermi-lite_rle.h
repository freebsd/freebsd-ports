--- SeqLib/fermi-lite/rle.h.orig	2016-09-01 20:47:53 UTC
+++ SeqLib/fermi-lite/rle.h
@@ -30,7 +30,7 @@ extern "C" {
  *** 43+3 codec ***
  ******************/
 
-const uint8_t rle_auxtab[8];
+extern const uint8_t rle_auxtab[8];
 
 #define RLE_MIN_SPACE 18
 #define rle_nptr(block) ((uint16_t*)(block))
