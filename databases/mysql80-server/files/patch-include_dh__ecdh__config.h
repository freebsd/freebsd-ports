--- include/dh_ecdh_config.h.orig	2024-07-12 19:15:25 UTC
+++ include/dh_ecdh_config.h
@@ -39,7 +39,7 @@ namespace {
 #endif /* OPENSSL_VERSION_NUMBER < 0x10002000L */
 
 namespace {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 /* Following primes are from https://www.rfc-editor.org/rfc/rfc7919#appendix-A
  */
 
@@ -258,6 +258,7 @@ bool set_dh(SSL_CTX *ctx) {
 
   DH *dh = nullptr;
 #if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if !defined(LIBRESSL_VERSION_NUMBER)
   switch (security_level) {
     case 1:
       [[fallthrough]];
@@ -276,6 +277,43 @@ bool set_dh(SSL_CTX *ctx) {
     default:
       break;
   };
+#else
+  dh = DH_new();
+  if (!dh) return true;
+
+  BIGNUM *dhp = nullptr;
+  BIGNUM *dhg = nullptr;
+  switch (security_level) {
+    case 1:
+      [[fallthrough]];
+    case 2:
+      dhp =
+          BN_bin2bn(rfc7919_ffdhe2048_p, sizeof(rfc7919_ffdhe2048_p), nullptr);
+      break;
+    case 3:
+      dhp =
+          BN_bin2bn(rfc7919_ffdhe3072_p, sizeof(rfc7919_ffdhe3072_p), nullptr);
+      break;
+    case 4:
+      dhp =
+          BN_bin2bn(rfc7919_ffdhe8192_p, sizeof(rfc7919_ffdhe8192_p), nullptr);
+      break;
+    case 5:
+      /* There is no RFC7919 approved prime for sec level 5 */
+      [[fallthrough]];
+    default:
+      DH_free(dh);
+      return true;
+  };
+
+  dhg = BN_bin2bn(rfc7919_g, sizeof(rfc7919_g), nullptr);
+  if (!dhp || !dhg || !DH_set0_pqg(dh, dhp, nullptr, dhg)) {
+    DH_free(dh);
+    BN_free(dhg);
+    BN_free(dhp);
+    return true;
+  }
+#endif /* !defined(LIBRESSL_VERSION_NUMBER) */
 #else  /* OPENSSL_VERSION_NUMBER >= 0x10100000L */
   dh = DH_new();
   if (!dh) return true;
