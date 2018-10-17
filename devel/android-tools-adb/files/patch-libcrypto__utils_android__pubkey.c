--- libcrypto_utils/android_pubkey.c.orig	2016-04-16 00:01:39 UTC
+++ libcrypto_utils/android_pubkey.c
@@ -61,10 +61,49 @@ static void reverse_bytes(uint8_t* buffer, size_t size
   }
 }
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
+// http://github.com/google/boringssl/commit/5a91503826ad
+static void RSA_get0_key(const RSA *rsa, const BIGNUM **out_n, const BIGNUM **out_e,
+                         const BIGNUM **out_d) {
+  if (out_n != NULL) {
+    *out_n = rsa->n;
+  }
+  if (out_e != NULL) {
+    *out_e = rsa->e;
+  }
+  if (out_d != NULL) {
+    *out_d = rsa->d;
+  }
+}
+
+static int RSA_set0_key(RSA *rsa, BIGNUM *n, BIGNUM *e, BIGNUM *d) {
+  if ((rsa->n == NULL && n == NULL) ||
+      (rsa->e == NULL && e == NULL)) {
+    return 0;
+  }
+
+  if (n != NULL) {
+    BN_free(rsa->n);
+    rsa->n = n;
+  }
+  if (e != NULL) {
+    BN_free(rsa->e);
+    rsa->e = e;
+  }
+  if (d != NULL) {
+    BN_free(rsa->d);
+    rsa->d = d;
+  }
+
+  return 1;
+}
+#endif
+
 bool android_pubkey_decode(const uint8_t* key_buffer, size_t size, RSA** key) {
   const RSAPublicKey* key_struct = (RSAPublicKey*)key_buffer;
   bool ret = false;
   uint8_t modulus_buffer[ANDROID_PUBKEY_MODULUS_SIZE];
+  BIGNUM *new_key_n, *new_key_e;
   RSA* new_key = RSA_new();
   if (!new_key) {
     goto cleanup;
@@ -81,14 +120,14 @@ bool android_pubkey_decode(const uint8_t* key_buffer, 
   // Convert the modulus to big-endian byte order as expected by BN_bin2bn.
   memcpy(modulus_buffer, key_struct->modulus, sizeof(modulus_buffer));
   reverse_bytes(modulus_buffer, sizeof(modulus_buffer));
-  new_key->n = BN_bin2bn(modulus_buffer, sizeof(modulus_buffer), NULL);
-  if (!new_key->n) {
+  new_key_n = BN_bin2bn(modulus_buffer, sizeof(modulus_buffer), NULL);
+  if (!new_key_n) {
     goto cleanup;
   }
 
   // Read the exponent.
-  new_key->e = BN_new();
-  if (!new_key->e || !BN_set_word(new_key->e, key_struct->exponent)) {
+  new_key_e = BN_new();
+  if (!new_key_e || !BN_set_word(new_key_e, key_struct->exponent)) {
     goto cleanup;
   }
 
@@ -100,6 +139,7 @@ bool android_pubkey_decode(const uint8_t* key_buffer, 
   // be added here if/when we want the additional speedup from using the
   // pre-computed montgomery parameters.
 
+  RSA_set0_key(new_key, new_key_n, new_key_e, NULL);
   *key = new_key;
   ret = true;
 
@@ -110,6 +150,83 @@ cleanup:
   return ret;
 }
 
+#if !defined(OPENSSL_IS_BORINGSSL)
+// https://android.googlesource.com/platform/external/chromium_org/third_party/boringssl/src/+/6887edb%5E!/
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
+struct bignum_st {
+  BN_ULONG *d; /* Pointer to an array of 'BN_BITS2' bit chunks in little-endian
+                  order. */
+  int top;    // Index of last used element in |d|, plus one.
+  int dmax;   // Size of |d|, in words.
+  int neg;    // one if the number is negative
+  int flags;  // bitmask of BN_FLG_* values
+};
+#endif
+
+// constant_time_select_ulong returns |x| if |v| is 1 and |y| if |v| is 0. Its
+// behavior is undefined if |v| takes any other value.
+static BN_ULONG constant_time_select_ulong(int v, BN_ULONG x, BN_ULONG y) {
+  BN_ULONG mask = v;
+  mask--;
+
+  return (~mask & x) | (mask & y);
+}
+
+// constant_time_le_size_t returns 1 if |x| <= |y| and 0 otherwise. |x| and |y|
+// must not have their MSBs set.
+static int constant_time_le_size_t(size_t x, size_t y) {
+  return ((x - y - 1) >> (sizeof(size_t) * 8 - 1)) & 1;
+}
+
+// read_word_padded returns the |i|'th word of |in|, if it is not out of
+// bounds. Otherwise, it returns 0. It does so without branches on the size of
+// |in|, however it necessarily does not have the same memory access pattern. If
+// the access would be out of bounds, it reads the last word of |in|. |in| must
+// not be zero.
+static BN_ULONG read_word_padded(const BIGNUM *in, size_t i) {
+  // Read |in->d[i]| if valid. Otherwise, read the last word.
+  BN_ULONG l = in->d[constant_time_select_ulong(
+      constant_time_le_size_t(in->dmax, i), in->dmax - 1, i)];
+
+  // Clamp to zero if above |d->top|.
+  return constant_time_select_ulong(constant_time_le_size_t(in->top, i), 0, l);
+}
+
+int BN_bn2bin_padded(uint8_t *out, size_t len, const BIGNUM *in) {
+  // Special case for |in| = 0. Just branch as the probability is negligible.
+  if (BN_is_zero(in)) {
+    memset(out, 0, len);
+    return 1;
+  }
+
+  // Check if the integer is too big. This case can exit early in non-constant
+  // time.
+  if ((size_t)in->top > (len + (BN_BYTES - 1)) / BN_BYTES) {
+    return 0;
+  }
+  if ((len % BN_BYTES) != 0) {
+    BN_ULONG l = read_word_padded(in, len / BN_BYTES);
+    if (l >> (8 * (len % BN_BYTES)) != 0) {
+      return 0;
+    }
+  }
+
+  // Write the bytes out one by one. Serialization is done without branching on
+  // the bits of |in| or on |in->top|, but if the routine would otherwise read
+  // out of bounds, the memory access pattern can't be fixed. However, for an
+  // RSA key of size a multiple of the word size, the probability of BN_BYTES
+  // leading zero octets is low.
+  //
+  // See Falko Stenzke, "Manger's Attack revisited", ICICS 2010.
+  size_t i = len;
+  while (i--) {
+    BN_ULONG l = read_word_padded(in, i / BN_BYTES);
+    *(out++) = (uint8_t)(l >> (8 * (i % BN_BYTES))) & 0xff;
+  }
+  return 1;
+}
+#endif
+
 static bool android_pubkey_encode_bignum(const BIGNUM* num, uint8_t* buffer) {
   if (!BN_bn2bin_padded(buffer, ANDROID_PUBKEY_MODULUS_SIZE, num)) {
     return false;
@@ -120,6 +237,7 @@ static bool android_pubkey_encode_bignum(const BIGNUM*
 }
 
 bool android_pubkey_encode(const RSA* key, uint8_t* key_buffer, size_t size) {
+  const BIGNUM *key_n, *key_e;
   RSAPublicKey* key_struct = (RSAPublicKey*)key_buffer;
   bool ret = false;
   BN_CTX* ctx = BN_CTX_new();
@@ -136,27 +254,28 @@ bool android_pubkey_encode(const RSA* key, uint8_t* ke
   key_struct->modulus_size_words = ANDROID_PUBKEY_MODULUS_SIZE_WORDS;
 
   // Compute and store n0inv = -1 / N[0] mod 2^32.
+  RSA_get0_key(key, &key_n, &key_e, NULL);
   if (!ctx || !r32 || !n0inv || !BN_set_bit(r32, 32) ||
-      !BN_mod(n0inv, key->n, r32, ctx) ||
+      !BN_mod(n0inv, key_n, r32, ctx) ||
       !BN_mod_inverse(n0inv, n0inv, r32, ctx) || !BN_sub(n0inv, r32, n0inv)) {
     goto cleanup;
   }
   key_struct->n0inv = (uint32_t)BN_get_word(n0inv);
 
   // Store the modulus.
-  if (!android_pubkey_encode_bignum(key->n, key_struct->modulus)) {
+  if (!android_pubkey_encode_bignum(key_n, key_struct->modulus)) {
     goto cleanup;
   }
 
   // Compute and store rr = (2^(rsa_size)) ^ 2 mod N.
   if (!ctx || !rr || !BN_set_bit(rr, ANDROID_PUBKEY_MODULUS_SIZE * 8) ||
-      !BN_mod_sqr(rr, rr, key->n, ctx) ||
+      !BN_mod_sqr(rr, rr, key_n, ctx) ||
       !android_pubkey_encode_bignum(rr, key_struct->rr)) {
     goto cleanup;
   }
 
   // Store the exponent.
-  key_struct->exponent = (uint32_t)BN_get_word(key->e);
+  key_struct->exponent = (uint32_t)BN_get_word(key_e);
 
   ret = true;
 
