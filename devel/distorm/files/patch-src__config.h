--- src/config.h.orig	2011-06-14 14:58:29.000000000 -0400
+++ src/config.h	2011-12-28 00:17:59.000000000 -0500
@@ -133,27 +133,51 @@
  * These functions can read from the stream safely!
  * Swap endianity of input to little endian.
  */
+#ifdef __GNUC__
+_INLINE_ int16_t RSHORT(const uint8_t *s)
+#else
 static _INLINE_ int16_t RSHORT(const uint8_t *s)
+#endif
 {
 	return s[0] | (s[1] << 8);
 }
+#ifdef __GNUC__
+_INLINE_ uint16_t RUSHORT(const uint8_t *s)
+#else
 static _INLINE_ uint16_t RUSHORT(const uint8_t *s)
+#endif
 {
 	return s[0] | (s[1] << 8);
 }
+#ifdef __GNUC__
+_INLINE_ int32_t RLONG(const uint8_t *s)
+#else
 static _INLINE_ int32_t RLONG(const uint8_t *s)
+#endif
 {
 	return s[0] | (s[1] << 8) | (s[2] << 16) | (s[3] << 24);
 }
+#ifdef __GNUC__
+_INLINE_ uint32_t RULONG(const uint8_t *s)
+#else
 static _INLINE_ uint32_t RULONG(const uint8_t *s)
+#endif
 {
 	return s[0] | (s[1] << 8) | (s[2] << 16) | (s[3] << 24);
 }
+#ifdef __GNUC__
+_INLINE_ int64_t RLLONG(const uint8_t *s)
+#else
 static _INLINE_ int64_t RLLONG(const uint8_t *s)
+#endif
 {
 	return s[0] | (s[1] << 8) | (s[2] << 16) | (s[3] << 24) | ((uint64_t)s[4] << 32) | ((uint64_t)s[5] << 40) | ((uint64_t)s[6] << 48) | ((uint64_t)s[7] << 56);
 }
+#ifdef __GNUC__
+_INLINE_ uint64_t RULLONG(const uint8_t *s)
+#else
 static _INLINE_ uint64_t RULLONG(const uint8_t *s)
+#endif
 {
 	return s[0] | (s[1] << 8) | (s[2] << 16) | (s[3] << 24) | ((uint64_t)s[4] << 32) | ((uint64_t)s[5] << 40) | ((uint64_t)s[6] << 48) | ((uint64_t)s[7] << 56);
 }
