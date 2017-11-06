--- libcrypto_utils/android_pubkey.c.orig	2016-04-16 00:01:39 UTC
+++ libcrypto_utils/android_pubkey.c
@@ -110,6 +110,76 @@ cleanup:
   return ret;
 }
 
+#if !defined(OPENSSL_IS_BORINGSSL)
+// https://android.googlesource.com/platform/external/chromium_org/third_party/boringssl/src/+/6887edb%5E!/
+
+/* constant_time_select_ulong returns |x| if |v| is 1 and |y| if |v| is 0. Its
+ * behavior is undefined if |v| takes any other value. */
+static BN_ULONG constant_time_select_ulong(int v, BN_ULONG x, BN_ULONG y) {
+  BN_ULONG mask = v;
+  mask--;
+
+  return (~mask & x) | (mask & y);
+}
+
+/* constant_time_le_size_t returns 1 if |x| <= |y| and 0 otherwise. |x| and |y|
+ * must not have their MSBs set. */
+static int constant_time_le_size_t(size_t x, size_t y) {
+  return ((x - y - 1) >> (sizeof(size_t) * 8 - 1)) & 1;
+}
+
+/* read_word_padded returns the |i|'th word of |in|, if it is not out of
+ * bounds. Otherwise, it returns 0. It does so without branches on the size of
+ * |in|, however it necessarily does not have the same memory access pattern. If
+ * the access would be out of bounds, it reads the last word of |in|. |in| must
+ * not be zero. */
+static BN_ULONG read_word_padded(const BIGNUM *in, size_t i) {
+  /* Read |in->d[i]| if valid. Otherwise, read the last word. */
+  BN_ULONG l = in->d[constant_time_select_ulong(
+      constant_time_le_size_t(in->dmax, i), in->dmax - 1, i)];
+
+  /* Clamp to zero if above |d->top|. */
+  return constant_time_select_ulong(constant_time_le_size_t(in->top, i), 0, l);
+}
+
+static int BN_bn2bin_padded(uint8_t *out, size_t len, const BIGNUM *in) {
+  size_t i;
+  BN_ULONG l;
+
+  /* Special case for |in| = 0. Just branch as the probability is negligible. */
+  if (BN_is_zero(in)) {
+    memset(out, 0, len);
+    return 1;
+  }
+
+  /* Check if the integer is too big. This case can exit early in non-constant
+   * time. */
+  if ((size_t)in->top > (len + (BN_BYTES - 1)) / BN_BYTES) {
+    return 0;
+  }
+  if ((len % BN_BYTES) != 0) {
+    l = read_word_padded(in, len / BN_BYTES);
+    if (l >> (8 * (len % BN_BYTES)) != 0) {
+      return 0;
+    }
+  }
+
+  /* Write the bytes out one by one. Serialization is done without branching on
+   * the bits of |in| or on |in->top|, but if the routine would otherwise read
+   * out of bounds, the memory access pattern can't be fixed. However, for an
+   * RSA key of size a multiple of the word size, the probability of BN_BYTES
+   * leading zero octets is low.
+   *
+   * See Falko Stenzke, "Manger's Attack revisited", ICICS 2010. */
+  i = len;
+  while (i--) {
+    l = read_word_padded(in, i / BN_BYTES);
+    *(out++) = (uint8_t)(l >> (8 * (i % BN_BYTES))) & 0xff;
+  }
+  return 1;
+}
+#endif
+
 static bool android_pubkey_encode_bignum(const BIGNUM* num, uint8_t* buffer) {
   if (!BN_bn2bin_padded(buffer, ANDROID_PUBKEY_MODULUS_SIZE, num)) {
     return false;
