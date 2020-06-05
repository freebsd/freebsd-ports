--- src/mesa/main/macros.h.orig	2019-06-26 20:14:08 UTC
+++ src/mesa/main/macros.h
@@ -677,6 +677,10 @@ minify(unsigned value, unsigned levels)
  *
  * \sa ROUND_DOWN_TO()
  */
+#ifdef __FreeBSD__
+#undef ALIGN
+#endif
+
 static inline uintptr_t
 ALIGN(uintptr_t value, int32_t alignment)
 {
