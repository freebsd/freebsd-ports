--- src/plugins/tls/openssl/qsslsocket_openssl_symbols.cpp.orig	2023-11-15 13:58:42 UTC
+++ src/plugins/tls/openssl/qsslsocket_openssl_symbols.cpp
@@ -112,23 +112,36 @@ DEFINEFUNC(int, EVP_PKEY_up_ref, EVP_PKEY *a, a, retur
 DEFINEFUNC2(int, BN_is_word, BIGNUM *a, a, BN_ULONG w, w, return 0, return)
 DEFINEFUNC(int, EVP_CIPHER_CTX_reset, EVP_CIPHER_CTX *c, c, return 0, return)
 DEFINEFUNC(int, EVP_PKEY_up_ref, EVP_PKEY *a, a, return 0, return)
+#ifdef OPENSSL_NO_DEPRECATED_3_0
 DEFINEFUNC2(EVP_PKEY_CTX *, EVP_PKEY_CTX_new, EVP_PKEY *pkey, pkey, ENGINE *e, e, return nullptr, return)
 DEFINEFUNC(int, EVP_PKEY_param_check, EVP_PKEY_CTX *ctx, ctx, return 0, return)
 DEFINEFUNC(void, EVP_PKEY_CTX_free, EVP_PKEY_CTX *ctx, ctx, return, return)
+#endif // OPENSSL_NO_DEPRECATED_3_0
+#ifndef LIBRESSL_VERSION_NUMBER
 DEFINEFUNC(int, OPENSSL_sk_num, OPENSSL_STACK *a, a, return -1, return)
 DEFINEFUNC2(void, OPENSSL_sk_pop_free, OPENSSL_STACK *a, a, void (*b)(void*), b, return, DUMMYARG)
 DEFINEFUNC(OPENSSL_STACK *, OPENSSL_sk_new_null, DUMMYARG, DUMMYARG, return nullptr, return)
 DEFINEFUNC2(void, OPENSSL_sk_push, OPENSSL_STACK *a, a, void *b, b, return, DUMMYARG)
 DEFINEFUNC(void, OPENSSL_sk_free, OPENSSL_STACK *a, a, return, DUMMYARG)
 DEFINEFUNC2(void *, OPENSSL_sk_value, OPENSSL_STACK *a, a, int b, b, return nullptr, return)
+#else
+DEFINEFUNC(int, sk_num, STACK *a, a, return -1, return)
+DEFINEFUNC2(void, sk_pop_free, STACK *a, a, void (*b)(void*), b, return, DUMMYARG)
+DEFINEFUNC(_STACK *, sk_new_null, DUMMYARG, DUMMYARG, return nullptr, return)
+DEFINEFUNC2(void, sk_push, _STACK *a, a, void *b, b, return, DUMMYARG)
+DEFINEFUNC(void, sk_free, _STACK *a, a, return, DUMMYARG)
+DEFINEFUNC2(void *, sk_value, STACK *a, a, int b, b, return nullptr, return)
+#endif // LIBRESSL_VERSION_NUMBER
 DEFINEFUNC(int, SSL_session_reused, SSL *a, a, return 0, return)
 DEFINEFUNC2(qssloptions, SSL_CTX_set_options, SSL_CTX *ctx, ctx, qssloptions op, op, return 0, return)
 using info_callback = void (*) (const SSL *ssl, int type, int val);
 DEFINEFUNC2(void, SSL_set_info_callback, SSL *ssl, ssl, info_callback cb, cb, return, return)
 DEFINEFUNC(const char *, SSL_alert_type_string, int value, value, return nullptr, return)
 DEFINEFUNC(const char *, SSL_alert_desc_string_long, int value, value, return nullptr, return)
+#ifndef LIBRESSL_VERSION_NUMBER
 DEFINEFUNC(int, SSL_CTX_get_security_level, const SSL_CTX *ctx, ctx, return -1, return)
 DEFINEFUNC2(void, SSL_CTX_set_security_level, SSL_CTX *ctx, ctx, int level, level, return, return)
+#endif // LIBRESSL_VERSION_NUMBER
 #ifdef TLS1_3_VERSION
 DEFINEFUNC2(int, SSL_CTX_set_ciphersuites, SSL_CTX *ctx, ctx, const char *str, str, return 0, return)
 DEFINEFUNC2(void, SSL_set_psk_use_session_callback, SSL *ssl, ssl, q_SSL_psk_use_session_cb_func_t callback, callback, return, DUMMYARG)
@@ -154,7 +167,11 @@ DEFINEFUNC(STACK_OF(X509) *, X509_STORE_CTX_get0_chain
 DEFINEFUNC3(int, X509_STORE_set_ex_data, X509_STORE *a, a, int idx, idx, void *data, data, return 0, return)
 DEFINEFUNC2(void *, X509_STORE_get_ex_data, X509_STORE *r, r, int idx, idx, return nullptr, return)
 DEFINEFUNC(STACK_OF(X509) *, X509_STORE_CTX_get0_chain, X509_STORE_CTX *a, a, return nullptr, return)
+#ifndef LIBRESSL_VERSION_NUMBER
 DEFINEFUNC3(void, CRYPTO_free, void *str, str, const char *file, file, int line, line, return, DUMMYARG)
+#else
+DEFINEFUNC(void, CRYPTO_free, void *a, a, return, DUMMYARG)
+#endif
 DEFINEFUNC3(int, CRYPTO_memcmp, const void * in_a, in_a, const void * in_b, in_b, size_t len, len, return 1, return);
 DEFINEFUNC(long, OpenSSL_version_num, void, DUMMYARG, return 0, return)
 DEFINEFUNC(const char *, OpenSSL_version, int a, a, return nullptr, return)
@@ -193,7 +210,9 @@ DEFINEFUNC2(OCSP_RESPONSE *, OCSP_response_create, int
             ASN1_OCTET_STRING **piKeyHash, piKeyHash, ASN1_INTEGER **pserial, pserial, OCSP_CERTID *cid, cid,
             return 0, return)
 DEFINEFUNC2(OCSP_RESPONSE *, OCSP_response_create, int status, status, OCSP_BASICRESP *bs, bs, return nullptr, return)
+#if !defined(LIBRESSL_VERSION_NUMBER) || (LIBRESSL_VERSION_NUMBER >= 0x3050000fL)
 DEFINEFUNC(const STACK_OF(X509) *, OCSP_resp_get0_certs, const OCSP_BASICRESP *bs, bs, return nullptr, return)
+#endif
 DEFINEFUNC2(int, OCSP_id_cmp, OCSP_CERTID *a, a, OCSP_CERTID *b, b, return -1, return)
 DEFINEFUNC7(OCSP_SINGLERESP *, OCSP_basic_add1_status, OCSP_BASICRESP *r, r, OCSP_CERTID *c, c, int s, s,
             int re, re, ASN1_TIME *rt, rt, ASN1_TIME *t, t, ASN1_TIME *n, n, return nullptr, return)
@@ -214,7 +233,9 @@ DEFINEFUNC2(int, ASN1_STRING_to_UTF8, unsigned char **
 DEFINEFUNC2(int, ASN1_INTEGER_cmp, const ASN1_INTEGER *a, a, const ASN1_INTEGER *b, b, return 1, return)
 DEFINEFUNC(int, ASN1_STRING_length, ASN1_STRING *a, a, return 0, return)
 DEFINEFUNC2(int, ASN1_STRING_to_UTF8, unsigned char **a, a, ASN1_STRING *b, b, return 0, return)
+#if !defined(LIBRESSL_VERSION_NUMBER) || (LIBRESSL_VERSION_NUMBER >= 0x3060000fL)
 DEFINEFUNC2(int, ASN1_TIME_to_tm, const ASN1_TIME *s, s, struct tm *tm, tm, return 0, return)
+#endif
 DEFINEFUNC4(long, BIO_ctrl, BIO *a, a, int b, b, long c, c, void *d, d, return -1, return)
 DEFINEFUNC(int, BIO_free, BIO *a, a, return 0, return)
 DEFINEFUNC2(BIO *, BIO_new_mem_buf, void *a, a, int b, b, return nullptr, return)
@@ -289,12 +310,14 @@ DEFINEFUNC(X509_STORE *, SSL_CTX_get_cert_store, const
 DEFINEFUNC2(int, SSL_CTX_use_PrivateKey, SSL_CTX *a, a, EVP_PKEY *b, b, return -1, return)
 DEFINEFUNC3(int, SSL_CTX_use_PrivateKey_file, SSL_CTX *a, a, const char *b, b, int c, c, return -1, return)
 DEFINEFUNC(X509_STORE *, SSL_CTX_get_cert_store, const SSL_CTX *a, a, return nullptr, return)
+#ifndef LIBRESSL_VERSION_NUMBER
 DEFINEFUNC(SSL_CONF_CTX *, SSL_CONF_CTX_new, DUMMYARG, DUMMYARG, return nullptr, return);
 DEFINEFUNC(void, SSL_CONF_CTX_free, SSL_CONF_CTX *a, a, return ,return);
 DEFINEFUNC2(void, SSL_CONF_CTX_set_ssl_ctx, SSL_CONF_CTX *a, a, SSL_CTX *b, b, return, return);
 DEFINEFUNC2(unsigned int, SSL_CONF_CTX_set_flags, SSL_CONF_CTX *a, a, unsigned int b, b, return 0, return);
 DEFINEFUNC(int, SSL_CONF_CTX_finish, SSL_CONF_CTX *a, a, return 0, return);
 DEFINEFUNC3(int, SSL_CONF_cmd, SSL_CONF_CTX *a, a, const char *b, b, const char *c, c, return 0, return);
+#endif
 DEFINEFUNC(void, SSL_free, SSL *a, a, return, DUMMYARG)
 DEFINEFUNC(STACK_OF(SSL_CIPHER) *, SSL_get_ciphers, const SSL *a, a, return nullptr, return)
 DEFINEFUNC(const SSL_CIPHER *, SSL_get_current_cipher, SSL *a, a, return nullptr, return)
@@ -761,8 +784,8 @@ static LoadedOpenSsl loadOpenSsl()
     libcrypto->setFileNameAndVersion("crypto"_L1, shlibVersion);
 #elif defined(SHLIB_VERSION_NUMBER)
     // first attempt: the canonical name is libssl.so.<SHLIB_VERSION_NUMBER>
-    libssl->setFileNameAndVersion("ssl"_L1, SHLIB_VERSION_NUMBER ""_L1);
-    libcrypto->setFileNameAndVersion("crypto"_L1, SHLIB_VERSION_NUMBER ""_L1);
+    libssl->setFileNameAndVersion("%%OPENSSLLIB%%/libssl"_L1, SHLIB_VERSION_NUMBER ""_L1);
+    libcrypto->setFileNameAndVersion("%%OPENSSLLIB%%/libcrypto"_L1, SHLIB_VERSION_NUMBER ""_L1);
 #endif // OPENSSL_SHLIB_VERSION
 
     if (libcrypto->load() && libssl->load()) {
@@ -795,8 +818,8 @@ static LoadedOpenSsl loadOpenSsl()
     libssl->setFileNameAndVersion("ssl"_L1 + suffix, -1);
     libcrypto->setFileNameAndVersion("crypto"_L1 + suffix, -1);
 # else
-    libssl->setFileNameAndVersion("ssl"_L1, -1);
-    libcrypto->setFileNameAndVersion("crypto"_L1, -1);
+    libssl->setFileNameAndVersion("%%OPENSSLLIB%%/libssl"_L1, -1);
+    libcrypto->setFileNameAndVersion("%%OPENSSLLIB%%/libcrypto"_L1, -1);
 # endif
     if (libcrypto->load() && libssl->load()) {
         // libssl.so.0 and libcrypto.so.0 found
@@ -865,21 +888,34 @@ bool q_resolveOpenSslSymbols()
         RESOLVEFUNC(EVP_CIPHER_CTX_reset)
         RESOLVEFUNC(AUTHORITY_INFO_ACCESS_free)
         RESOLVEFUNC(EVP_PKEY_up_ref)
+#ifdef OPENSSL_NO_DEPRECATED_3_0
         RESOLVEFUNC(EVP_PKEY_CTX_new)
         RESOLVEFUNC(EVP_PKEY_param_check)
         RESOLVEFUNC(EVP_PKEY_CTX_free)
+#endif // OPENSSL_NO_DEPRECATED_3_0
+#if !defined(LIBRESSL_VERSION_NUMBER)
         RESOLVEFUNC(OPENSSL_sk_new_null)
         RESOLVEFUNC(OPENSSL_sk_push)
         RESOLVEFUNC(OPENSSL_sk_free)
         RESOLVEFUNC(OPENSSL_sk_num)
         RESOLVEFUNC(OPENSSL_sk_pop_free)
         RESOLVEFUNC(OPENSSL_sk_value)
+#else
+        RESOLVEFUNC(sk_new_null)
+        RESOLVEFUNC(sk_push)
+        RESOLVEFUNC(sk_free)
+        RESOLVEFUNC(sk_num)
+        RESOLVEFUNC(sk_pop_free)
+        RESOLVEFUNC(sk_value)
+#endif
         RESOLVEFUNC(SSL_CTX_set_options)
         RESOLVEFUNC(SSL_set_info_callback)
         RESOLVEFUNC(SSL_alert_type_string)
         RESOLVEFUNC(SSL_alert_desc_string_long)
+#if !defined(LIBRESSL_VERSION_NUMBER)
         RESOLVEFUNC(SSL_CTX_get_security_level)
         RESOLVEFUNC(SSL_CTX_set_security_level)
+#endif
 #ifdef TLS1_3_VERSION
         RESOLVEFUNC(SSL_CTX_set_ciphersuites)
         RESOLVEFUNC(SSL_set_psk_use_session_callback)
@@ -961,7 +997,9 @@ bool q_resolveOpenSslSymbols()
         RESOLVEFUNC(OCSP_check_validity)
         RESOLVEFUNC(OCSP_cert_to_id)
         RESOLVEFUNC(OCSP_id_get0_info)
-        RESOLVEFUNC(OCSP_resp_get0_certs)
+#if !defined(LIBRESSL_VERSION_NUMBER) || (LIBRESSL_VERSION_NUMBER >= 0x3050000fL)
+     RESOLVEFUNC(OCSP_resp_get0_certs)
+#endif
         RESOLVEFUNC(OCSP_basic_sign)
         RESOLVEFUNC(OCSP_response_create)
         RESOLVEFUNC(i2d_OCSP_RESPONSE)
@@ -1056,12 +1094,14 @@ bool q_resolveOpenSslSymbols()
         RESOLVEFUNC(SSL_CTX_use_PrivateKey)
         RESOLVEFUNC(SSL_CTX_use_PrivateKey_file)
         RESOLVEFUNC(SSL_CTX_get_cert_store);
+#ifndef LIBRESSL_VERSION_NUMBER
         RESOLVEFUNC(SSL_CONF_CTX_new);
         RESOLVEFUNC(SSL_CONF_CTX_free);
         RESOLVEFUNC(SSL_CONF_CTX_set_ssl_ctx);
         RESOLVEFUNC(SSL_CONF_CTX_set_flags);
         RESOLVEFUNC(SSL_CONF_CTX_finish);
         RESOLVEFUNC(SSL_CONF_cmd);
+#endif
         RESOLVEFUNC(SSL_accept)
         RESOLVEFUNC(SSL_clear)
         RESOLVEFUNC(SSL_connect)
@@ -1121,7 +1161,9 @@ bool q_resolveOpenSslSymbols()
         RESOLVEFUNC(RSA_free)
 
         RESOLVEFUNC(DH_bits)
+#if !defined(LIBRESSL_VERSION_NUMBER) || (LIBRESSL_VERSION_NUMBER >= 0x3050000fL)
         RESOLVEFUNC(DSA_bits)
+#endif
         RESOLVEFUNC(RSA_bits)
 
 #ifndef OPENSSL_NO_EC
