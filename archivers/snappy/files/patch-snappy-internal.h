--- snappy-internal.h.orig	2024-04-04 19:04:38 UTC
+++ snappy-internal.h
@@ -104,6 +104,15 @@ inline void V128_StoreU(V128* dst, V128 val) {
   vst1q_u8(reinterpret_cast<uint8_t*>(dst), val);
 }
 
+#ifdef __arm__
+inline uint8x16_t vqtbl1q_u8(uint8x16_t table, uint8x16_t idx) {
+  uint8x8x2_t table2{vget_low_u8(table), vget_high_u8(table)};
+  uint8x8_t lo = vtbl2_u8(table2, vget_low_u8(idx));
+  uint8x8_t hi = vtbl2_u8(table2, vget_high_u8(idx));
+  return vcombine_u8(lo, hi);
+}
+#endif
+
 inline V128 V128_Shuffle(V128 input, V128 shuffle_mask) {
   assert(vminvq_u8(shuffle_mask) >= 0 && vmaxvq_u8(shuffle_mask) <= 15);
   return vqtbl1q_u8(input, shuffle_mask);
