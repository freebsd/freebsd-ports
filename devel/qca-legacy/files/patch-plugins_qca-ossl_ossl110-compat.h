--- plugins/qca-ossl/ossl110-compat.h.orig	2019-04-24 12:58:14 UTC
+++ plugins/qca-ossl/ossl110-compat.h
@@ -205,22 +205,6 @@ static int RSA_meth_set_priv_dec(RSA_METHOD *rsa, int 
     return 1;
 }
 
-static int RSA_meth_set_sign(RSA_METHOD *meth, int (*sign) (int type, const unsigned char *m,
-    unsigned int m_length, unsigned char *sigret, unsigned int *siglen, const RSA *rsa))
-{
-    if (!meth) return 0;
-    meth->rsa_sign = sign;
-    return 1;
-}
-
-static int RSA_meth_set_verify(RSA_METHOD *meth, int (*verify) (int dtype, const unsigned char *m,
-    unsigned int m_length, const unsigned char *sigbuf, unsigned int siglen, const RSA *rsa))
-{
-    if (!meth) return 0;
-    meth->rsa_verify = verify;
-    return 1;
-}
-
 static int RSA_meth_set_finish(RSA_METHOD *meth, int (*finish) (RSA *rsa))
 {
     if (!meth) return 0;
@@ -271,5 +255,23 @@ static void HMAC_CTX_free(HMAC_CTX *ctx)
 #define X509_REVOKED_get0_revocationDate(rev) (rev)->revocationDate
 
 #endif // OPENSSL_VERSION_NUMBER < 0x10100000L
+
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
+static int RSA_meth_set_sign(RSA_METHOD *meth, int (*sign) (int type, const unsigned char *m,
+    unsigned int m_length, unsigned char *sigret, unsigned int *siglen, const RSA *rsa))
+{
+    if (!meth) return 0;
+    meth->rsa_sign = sign;
+    return 1;
+}
+
+static int RSA_meth_set_verify(RSA_METHOD *meth, int (*verify) (int dtype, const unsigned char *m,
+    unsigned int m_length, const unsigned char *sigbuf, unsigned int siglen, const RSA *rsa))
+{
+    if (!meth) return 0;
+    meth->rsa_verify = verify;
+    return 1;
+}
+#endif // (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
 
 #endif // OSSL110COMPAT_H
