--- source/blender/blenlib/BLI_bit_span_to_index_ranges.hh.orig	2025-12-14 04:22:07 UTC
+++ source/blender/blenlib/BLI_bit_span_to_index_ranges.hh
@@ -111,7 +111,11 @@ inline void bits_to_index_ranges(const BitSpan bits, I
       /* Loads the next 128 bit. */
       const __m128i group = _mm_loadu_si128(reinterpret_cast<const __m128i *>(start + int_i));
       /* Checks if all the 128 bits are zero. */
+#if BLI_HAVE_SSE4
       const bool group_is_zero = _mm_testz_si128(group, group);
+#else
+      const bool group_is_zero = _mm_movemask_epi8(_mm_and_si128(group, group)) == 0;
+#endif
       if (group_is_zero) {
         continue;
       }
