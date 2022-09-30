--- src/cbang/openssl/KeyPair.cpp.orig	2022-09-17 22:00:36 UTC
+++ src/cbang/openssl/KeyPair.cpp
@@ -54,7 +54,10 @@
 #include <openssl/dh.h>
 #include <openssl/engine.h>
 #include <openssl/opensslv.h>
+
+#if 0x3000000fL <= OPENSSL_VERSION_NUMBER
 #include <openssl/core_names.h>
+#endif
 
 #include <string.h>
 
@@ -127,21 +130,44 @@ BigNum KeyPair::getParam(const char *id) const {
 
 
 BigNum KeyPair::getParam(const char *id) const {
+#if 0x3000000fL <= OPENSSL_VERSION_NUMBER
   BIGNUM *param = 0;
   EVP_PKEY_get_bn_param(key, id, &param);
   return BigNum(param, true);
+
+#else
+  THROW(__func__ << "() not supported with OpenSSL < v3.0");
+#endif
 }
 
 
 BigNum KeyPair::getRSA_E() const {
   if (!isRSA()) THROW("Not an RSA key");
+
+#if 0x3000000fL <= OPENSSL_VERSION_NUMBER
   return getParam(OSSL_PKEY_PARAM_RSA_E);
+
+#else
+  const BIGNUM *e;
+  RSA_get0_key(EVP_PKEY_get0_RSA(key), 0, &e, 0);
+  if (!e) THROW("RSA E not set");
+  return BigNum(e);
+#endif
 }
 
 
 BigNum KeyPair::getRSA_N() const {
   if (!isRSA()) THROW("Not an RSA key");
+
+#if 0x3000000fL <= OPENSSL_VERSION_NUMBER
   return getParam(OSSL_PKEY_PARAM_RSA_N);
+
+#else
+  const BIGNUM *n;
+  RSA_get0_key(EVP_PKEY_get0_RSA(key), &n, 0, 0);
+  if (!n) THROW("RSA N not set");
+  return BigNum(n);
+#endif
 }
 
 
@@ -154,14 +180,36 @@ BigNum KeyPair::getPublic() const  {
   case EVP_PKEY_EC:  return EC_KEY_get0_public_key(key->pkey.ec);
   }
 
-#else // OPENSSL_VERSION_NUMBER < 0x1010000fL
+#elif OPENSSL_VERSION_NUMBER < 0x3000000fL
+  const BIGNUM *n = 0;
+
   switch (EVP_PKEY_base_id(key)) {
+  case EVP_PKEY_RSA: RSA_get0_key(EVP_PKEY_get0_RSA(key), 0, &n, 0); return n;
+  case EVP_PKEY_DSA: DSA_get0_key(EVP_PKEY_get0_DSA(key), &n, 0); return n;
+  case EVP_PKEY_DH: DH_get0_key(EVP_PKEY_get0_DH(key), &n, 0); return n;
+  case EVP_PKEY_EC: {
+    const EC_KEY *ec = EVP_PKEY_get0_EC_KEY(key);
+    const EC_POINT *pt = EC_KEY_get0_public_key(ec);
+    const EC_GROUP *group = EC_KEY_get0_group(ec);
+    point_conversion_form_t form = EC_KEY_get_conv_form(ec);
+
+    if (pt && group) {
+      BIGNUM *n = BN_new();
+      EC_POINT_point2bn(group, pt, form, n, 0);
+      return BigNum(n, true);
+    }
+    return n;
+  }
+  }
+
+#else
+  switch (EVP_PKEY_base_id(key)) {
   case EVP_PKEY_RSA: return getParam(OSSL_PKEY_PARAM_RSA_E);
   case EVP_PKEY_DSA:
   case EVP_PKEY_DH:  return getParam(OSSL_PKEY_PARAM_PUB_KEY);
   case EVP_PKEY_EC:  break; // Cannot get EC pub key as a BigNum
   }
-#endif // OPENSSL_VERSION_NUMBER < 0x1010000fL
+#endif
 
   THROW("Invalid key type");
 }
@@ -176,14 +224,24 @@ BigNum KeyPair::getPrivate() const {
   case EVP_PKEY_EC:  return EC_KEY_get0_private_key(key->pkey.ec);
   }
 
-#else // OPENSSL_VERSION_NUMBER < 0x1010000fL
+#elif OPENSSL_VERSION_NUMBER < 0x3000000fL
+  const BIGNUM *n = 0;
+
   switch (EVP_PKEY_base_id(key)) {
+  case EVP_PKEY_RSA: RSA_get0_key(EVP_PKEY_get0_RSA(key), 0, 0, &n); return n;
+  case EVP_PKEY_DSA: DSA_get0_key(EVP_PKEY_get0_DSA(key), 0, &n); return n;
+  case EVP_PKEY_DH: DH_get0_key(EVP_PKEY_get0_DH(key), 0, &n); return n;
+  case EVP_PKEY_EC: return EC_KEY_get0_private_key(EVP_PKEY_get0_EC_KEY(key));
+  }
+
+#else
+  switch (EVP_PKEY_base_id(key)) {
   case EVP_PKEY_RSA: return getParam(OSSL_PKEY_PARAM_RSA_D);
   case EVP_PKEY_DSA:
   case EVP_PKEY_DH:
   case EVP_PKEY_EC:  return getParam(OSSL_PKEY_PARAM_PRIV_KEY);
   }
-#endif // OPENSSL_VERSION_NUMBER < 0x1010000fL
+#endif
 
   THROW("Invalid key type");
 }
@@ -197,8 +255,15 @@ bool KeyPair::match(const KeyPair &o) const {
 
 
 bool KeyPair::match(const KeyPair &o) const {
-  switch (EVP_PKEY_eq(key, o.key)) {
-  case 0: case -1: return false;
+#if 0x3000000fL <= OPENSSL_VERSION_NUMBER
+  int ret = EVP_PKEY_eq(key, o.key);
+  if (ret == -1) ret = 0;
+#else
+  int ret = EVP_PKEY_cmp(key, o.key);
+#endif
+
+  switch (ret) {
+  case 0: return false;
   case 1: return true;
   default: THROW("Error comparing keys: " << SSL::getErrorStr());
   }
