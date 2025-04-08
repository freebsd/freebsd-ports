--- Modules/_hashopenssl.c.orig	2024-12-03 18:42:41 UTC
+++ Modules/_hashopenssl.c
@@ -44,7 +44,9 @@
 
 #define MUNCH_SIZE INT_MAX
 
+#ifndef LIBRESSL_VERSION_NUMBER
 #define PY_OPENSSL_HAS_SCRYPT 1
+#endif
 #if defined(NID_sha3_224) && defined(NID_sha3_256) && defined(NID_sha3_384) && defined(NID_sha3_512)
 #define PY_OPENSSL_HAS_SHA3 1
 #endif
@@ -922,9 +924,12 @@ py_evp_fromname(PyObject *module, const char *digestna
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
 
