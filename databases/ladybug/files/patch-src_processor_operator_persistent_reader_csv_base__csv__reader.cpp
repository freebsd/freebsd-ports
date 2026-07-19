--- src/processor/operator/persistent/reader/csv/base_csv_reader.cpp.orig	2026-07-19 19:41:17 UTC
+++ src/processor/operator/persistent/reader/csv/base_csv_reader.cpp
@@ -626,6 +626,27 @@ static uint64_t findFirstNeonMatch(uint64_t position, 
     return position + 16;
 }
 
+#ifdef __aarch64__
+static inline bool
+is_nonzero(uint8x16_t a)
+{
+    return (vmaxvq_u8(a) != 0);
+}
+#else
+/* no vmaxvq_u8() on AArch32 */
+static inline bool
+is_nonzero(uint8x16_t a)
+{
+    uint8x8_t a8, a4;
+
+    a8 = vmax_u8(vget_low_u8(a), vget_high_u8(a));
+    a4 = vpmax_u8(a8, a8);
+
+    return (vget_lane_u32(a4, 0) != 0);
+}
+#endif /* defined(__aarch64__) */
+
+
 static uint64_t findNextCSVStructuralByteNEON(const char* buffer, uint64_t position,
     uint64_t bufferSize, const CSVOption& option, bool inQuotedField) {
     const auto quote = vdupq_n_u8(option.quoteChar);
@@ -643,7 +664,7 @@ static uint64_t findNextCSVStructuralByteNEON(const ch
         } else {
             mask = vorrq_u8(mask, vceqq_u8(bytes, delimiter));
         }
-        if (vmaxvq_u8(mask) != 0) {
+        if (is_nonzero(mask)) {
             vst1q_u8(matches, mask);
             return findFirstNeonMatch(position, matches);
         }
