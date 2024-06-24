--- Modules/_hashopenssl.c.orig	2024-04-02 08:25:04 UTC
+++ Modules/_hashopenssl.c
@@ -45,10 +45,21 @@
 
 #define MUNCH_SIZE INT_MAX
 
+#ifndef LIBRESSL_VERSION_NUMBER
 #define PY_OPENSSL_HAS_SCRYPT 1
+#endif
+
+#ifdef NID_sha3_224
 #define PY_OPENSSL_HAS_SHA3 1
+#endif
+
+#if defined(EVP_MD_FLAG_XOF) && defined(NID_shake128)
 #define PY_OPENSSL_HAS_SHAKE 1
+#endif
+
+#if defined(NID_blake2b512) && !defined(OPENSSL_NO_BLAKE2)
 #define PY_OPENSSL_HAS_BLAKE2 1
+#endif
 
 #if OPENSSL_VERSION_NUMBER >= 0x30000000L
 #define PY_EVP_MD EVP_MD
@@ -120,19 +131,27 @@ static const py_hashentry_t py_hashes[] = {
     PY_HASH_ENTRY(Py_hash_sha384, "SHA384", SN_sha384, NID_sha384),
     PY_HASH_ENTRY(Py_hash_sha512, "SHA512", SN_sha512, NID_sha512),
     /* truncated sha2 */
+#ifdef NID_sha512_224
     PY_HASH_ENTRY(Py_hash_sha512_224, "SHA512_224", SN_sha512_224, NID_sha512_224),
     PY_HASH_ENTRY(Py_hash_sha512_256, "SHA512_256", SN_sha512_256, NID_sha512_256),
+#endif
     /* sha3 */
+#ifdef PY_OPENSSL_HAS_SHA3
     PY_HASH_ENTRY(Py_hash_sha3_224, NULL, SN_sha3_224, NID_sha3_224),
     PY_HASH_ENTRY(Py_hash_sha3_256, NULL, SN_sha3_256, NID_sha3_256),
     PY_HASH_ENTRY(Py_hash_sha3_384, NULL, SN_sha3_384, NID_sha3_384),
     PY_HASH_ENTRY(Py_hash_sha3_512, NULL, SN_sha3_512, NID_sha3_512),
+#endif
     /* sha3 shake */
+#ifdef PY_OPENSSL_HAS_SHAKE
     PY_HASH_ENTRY(Py_hash_shake_128, NULL, SN_shake128, NID_shake128),
     PY_HASH_ENTRY(Py_hash_shake_256, NULL, SN_shake256, NID_shake256),
+#endif
     /* blake2 digest */
+#ifdef PY_OPENSSL_HAS_BLAKE2
     PY_HASH_ENTRY(Py_hash_blake2s, "blake2s256", SN_blake2s256, NID_blake2s256),
     PY_HASH_ENTRY(Py_hash_blake2b, "blake2b512", SN_blake2b512, NID_blake2b512),
+#endif
     PY_HASH_ENTRY(NULL, NULL, NULL, 0),
 };
 
@@ -874,9 +893,12 @@ py_evp_fromname(PyObject *module, const char *digestna
         goto exit;
     }
 
+#ifdef PY_OPENSSL_HAS_SHAKE
     if ((EVP_MD_flags(digest) & EVP_MD_FLAG_XOF) == EVP_MD_FLAG_XOF) {
         type = get_hashlib_state(module)->EVPXOFtype;
-    } else {
+    } else
+#endif
+    {
         type = get_hashlib_state(module)->EVPtype;
     }
 
