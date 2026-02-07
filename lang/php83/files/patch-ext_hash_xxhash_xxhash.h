--- ext/hash/xxhash/xxhash.h.orig	2023-06-06 15:54:29 UTC
+++ ext/hash/xxhash/xxhash.h
@@ -3078,22 +3078,32 @@ enum XXH_VECTOR_TYPE /* fake enum */ {
  * inconsistent intrinsics, spotty coverage, and multiple endiannesses.
  */
 #if XXH_VECTOR == XXH_VSX
+/* Annoyingly, these headers _may_ define three macros: `bool`, `vector`,
+ * and `pixel`. This is a problem for obvious reasons.
+ *
+ * These keywords are unnecessary; the spec literally says they are
+ * equivalent to `__bool`, `__vector`, and `__pixel` and may be undef'd
+ * after including the header.
+ *
+ * We use pragma push_macro/pop_macro to keep the namespace clean. */
+#  pragma push_macro("bool")
+#  pragma push_macro("vector")
+#  pragma push_macro("pixel")
+/* silence potential macro redefined warnings */
+#  undef bool
+#  undef vector
+#  undef pixel
+
 #  if defined(__s390x__)
 #    include <s390intrin.h>
 #  else
-/* gcc's altivec.h can have the unwanted consequence to unconditionally
- * #define bool, vector, and pixel keywords,
- * with bad consequences for programs already using these keywords for other purposes.
- * The paragraph defining these macros is skipped when __APPLE_ALTIVEC__ is defined.
- * __APPLE_ALTIVEC__ is _generally_ defined automatically by the compiler,
- * but it seems that, in some cases, it isn't.
- * Force the build macro to be defined, so that keywords are not altered.
- */
-#    if defined(__GNUC__) && !defined(__APPLE_ALTIVEC__)
-#      define __APPLE_ALTIVEC__
-#    endif
 #    include <altivec.h>
 #  endif
+
+/* Restore the original macro values, if applicable. */
+#  pragma pop_macro("pixel")
+#  pragma pop_macro("vector")
+#  pragma pop_macro("bool")
 
 typedef __vector unsigned long long xxh_u64x2;
 typedef __vector unsigned char xxh_u8x16;
