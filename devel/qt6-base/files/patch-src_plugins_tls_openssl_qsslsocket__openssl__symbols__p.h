--- src/plugins/tls/openssl/qsslsocket_openssl_symbols_p.h.orig	2023-09-13 16:02:48 UTC
+++ src/plugins/tls/openssl/qsslsocket_openssl_symbols_p.h
@@ -46,6 +46,13 @@ QT_BEGIN_NAMESPACE
 
 #define DUMMYARG
 
+#ifdef LIBRESSL_VERSION_NUMBER
+typedef _STACK STACK;
+typedef STACK OPENSSL_STACK;
+typedef void OPENSSL_INIT_SETTINGS;
+typedef int (*X509_STORE_CTX_verify_cb)(int ok,X509_STORE_CTX *ctx);
+#endif
+
 #if !defined QT_LINKED_OPENSSL
 // **************** Shared declarations ******************
 // ret func(arg)
@@ -203,15 +210,32 @@ int q_EVP_PKEY_up_ref(EVP_PKEY *a);
 void q_AUTHORITY_INFO_ACCESS_free(AUTHORITY_INFO_ACCESS *a);
 int q_EVP_CIPHER_CTX_reset(EVP_CIPHER_CTX *c);
 int q_EVP_PKEY_up_ref(EVP_PKEY *a);
+#ifdef OPENSSL_NO_DEPRECATED_3_0
 EVP_PKEY_CTX *q_EVP_PKEY_CTX_new(EVP_PKEY *pkey, ENGINE *e);
 void q_EVP_PKEY_CTX_free(EVP_PKEY_CTX *ctx);
+#endif // OPENSSL_NO_DEPRECATED_3_0
 int q_EVP_PKEY_param_check(EVP_PKEY_CTX *ctx);
+#ifndef LIBRESSL_VERSION_NUMBER
 int q_OPENSSL_sk_num(OPENSSL_STACK *a);
 void q_OPENSSL_sk_pop_free(OPENSSL_STACK *a, void (*b)(void *));
 OPENSSL_STACK *q_OPENSSL_sk_new_null();
 void q_OPENSSL_sk_push(OPENSSL_STACK *st, void *data);
 void q_OPENSSL_sk_free(OPENSSL_STACK *a);
 void * q_OPENSSL_sk_value(OPENSSL_STACK *a, int b);
+#else // LIBRESSL_VERSION_NUMBER
+int q_sk_num(STACK *a);
+#define q_OPENSSL_sk_num(a) q_sk_num(a)
+void q_sk_pop_free(STACK *a, void (*b)(void *));
+#define q_OPENSSL_sk_pop_free(a, b) q_sk_pop_free(a, b)
+STACK *q_sk_new_null();
+#define q_OPENSSL_sk_new_null() q_sk_new_null()
+void q_sk_push(STACK *st, void *data);
+#define q_OPENSSL_sk_push(st, data) q_sk_push(st, data)
+void q_sk_free(STACK *a);
+#define q_OPENSSL_sk_free q_sk_free
+void * q_sk_value(STACK *a, int b);
+#define q_OPENSSL_sk_value(a, b) q_sk_value(a, b)
+#endif // LIBRESSL_VERSION_NUMBER
 int q_SSL_session_reused(SSL *a);
 qssloptions q_SSL_CTX_set_options(SSL_CTX *ctx, qssloptions op);
 int q_OPENSSL_init_ssl(uint64_t opts, const OPENSSL_INIT_SETTINGS *settings);
@@ -237,9 +261,15 @@ STACK_OF(X509) *q_X509_STORE_CTX_get0_chain(X509_STORE
 # define q_SSL_load_error_strings() q_OPENSSL_init_ssl(OPENSSL_INIT_LOAD_SSL_STRINGS \
                                                        | OPENSSL_INIT_LOAD_CRYPTO_STRINGS, NULL)
 
+#ifndef LIBRESSL_VERSION_NUMBER
 #define q_SKM_sk_num(st) q_OPENSSL_sk_num((OPENSSL_STACK *)st)
 #define q_SKM_sk_value(type, st,i) (type *)q_OPENSSL_sk_value((OPENSSL_STACK *)st, i)
+#else // LIBRESSL_VERSION_NUMBER
+#define q_SKM_sk_num(type, st) ((int (*)(const STACK_OF(type) *))q_sk_num)(st)
+#define q_SKM_sk_value(type, st,i) ((type * (*)(const STACK_OF(type) *, int))q_sk_value)(st, i)
+#endif // LIBRESSL_VERSION_NUMBER
 
+
 #define q_OPENSSL_add_all_algorithms_conf()  q_OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_CIPHERS \
                                                                    | OPENSSL_INIT_ADD_ALL_DIGESTS \
                                                                    | OPENSSL_INIT_LOAD_CONFIG, NULL)
@@ -423,12 +453,14 @@ X509_STORE *q_SSL_CTX_get_cert_store(const SSL_CTX *a)
 int q_SSL_CTX_use_PrivateKey(SSL_CTX *a, EVP_PKEY *b);
 int q_SSL_CTX_use_PrivateKey_file(SSL_CTX *a, const char *b, int c);
 X509_STORE *q_SSL_CTX_get_cert_store(const SSL_CTX *a);
+#ifndef LIBRESSL_VERSION_NUMBER
 SSL_CONF_CTX *q_SSL_CONF_CTX_new();
 void q_SSL_CONF_CTX_free(SSL_CONF_CTX *a);
 void q_SSL_CONF_CTX_set_ssl_ctx(SSL_CONF_CTX *a, SSL_CTX *b);
 unsigned int q_SSL_CONF_CTX_set_flags(SSL_CONF_CTX *a, unsigned int b);
 int q_SSL_CONF_CTX_finish(SSL_CONF_CTX *a);
 int q_SSL_CONF_cmd(SSL_CONF_CTX *a, const char *b, const char *c);
+#endif // LIBRESSL_VERSION_NUMBER
 void q_SSL_free(SSL *a);
 STACK_OF(SSL_CIPHER) *q_SSL_get_ciphers(const SSL *a);
 const SSL_CIPHER *q_SSL_get_current_cipher(SSL *a);
@@ -536,14 +568,26 @@ void q_PKCS12_free(PKCS12 *pkcs12);
 #define q_BIO_get_mem_data(b, pp) (int)q_BIO_ctrl(b,BIO_CTRL_INFO,0,(char *)pp)
 #define q_BIO_pending(b) (int)q_BIO_ctrl(b,BIO_CTRL_PENDING,0,NULL)
 #define q_SSL_CTX_set_mode(ctx,op) q_SSL_CTX_ctrl((ctx),SSL_CTRL_MODE,(op),NULL)
+#ifndef LIBRESSL_VERSION_NUMBER
 #define q_sk_GENERAL_NAME_num(st) q_SKM_sk_num((st))
+#else
+#define q_sk_GENERAL_NAME_num(st) q_SKM_sk_num(GENERAL_NAME, (st))
+#endif
 #define q_sk_GENERAL_NAME_value(st, i) q_SKM_sk_value(GENERAL_NAME, (st), (i))
 
 void q_GENERAL_NAME_free(GENERAL_NAME *a);
 
+#ifndef LIBRESSL_VERSION_NUMBER
 #define q_sk_X509_num(st) q_SKM_sk_num((st))
+#else
+#define q_sk_X509_num(st) q_SKM_sk_num(X509, (st))
+#endif
 #define q_sk_X509_value(st, i) q_SKM_sk_value(X509, (st), (i))
+#ifndef LIBRESSL_VERSION_NUMBER
 #define q_sk_SSL_CIPHER_num(st) q_SKM_sk_num((st))
+#else
+#define q_sk_SSL_CIPHER_num(st)   q_SKM_sk_num(SSL_CIPHER, (st))
+#endif
 #define q_sk_SSL_CIPHER_value(st, i) q_SKM_sk_value(SSL_CIPHER, (st), (i))
 #define q_SSL_CTX_add_extra_chain_cert(ctx,x509) \
         q_SSL_CTX_ctrl(ctx,SSL_CTRL_EXTRA_CHAIN_CERT,0,(char *)x509)
@@ -645,7 +689,11 @@ int q_OCSP_id_get0_info(ASN1_OCTET_STRING **piNameHash
 int q_OCSP_id_get0_info(ASN1_OCTET_STRING **piNameHash, ASN1_OBJECT **pmd, ASN1_OCTET_STRING **pikeyHash,
                         ASN1_INTEGER **pserial, OCSP_CERTID *cid);
 
+#if defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x3050000fL
+#define q_OCSP_resp_get0_certs(bs) ((bs)->certs)
+#else
 const STACK_OF(X509) *q_OCSP_resp_get0_certs(const OCSP_BASICRESP *bs);
+#endif
 OCSP_CERTID *q_OCSP_cert_to_id(const EVP_MD *dgst, X509 *subject, X509 *issuer);
 void q_OCSP_CERTID_free(OCSP_CERTID *cid);
 int q_OCSP_id_cmp(OCSP_CERTID *a, OCSP_CERTID *b);
@@ -664,8 +712,15 @@ void *q_CRYPTO_malloc(size_t num, const char *file, in
 
 void *q_CRYPTO_malloc(size_t num, const char *file, int line);
 #define q_OPENSSL_malloc(num) q_CRYPTO_malloc(num, "", 0)
+
+#ifndef LIBRESSL_VERSION_NUMBER
 void q_CRYPTO_free(void *str, const char *file, int line);
 # define q_OPENSSL_free(addr) q_CRYPTO_free(addr, "", 0)
+#else
+void q_CRYPTO_free(void *a);
+# define q_OPENSSL_free(addr) q_CRYPTO_free(addr)
+#endif
+
 int q_CRYPTO_memcmp(const void * in_a, const void * in_b, size_t len);
 
 void q_SSL_set_info_callback(SSL *ssl, void (*cb) (const SSL *ssl, int type, int val));
@@ -729,7 +784,11 @@ int q_RSA_bits(RSA *a);
 
 int q_DH_bits(DH *dh);
 int q_RSA_bits(RSA *a);
+#if defined(LIBRESSL_VERSION_NUMBER) && (LIBRESSL_VERSION_NUMBER < 0x3050000fL)
+#define q_DSA_bits(dsa) q_BN_num_bits((dsa)->p)
+#else
 int q_DSA_bits(DSA *a);
+#endif
 
 int q_EVP_PKEY_assign(EVP_PKEY *a, int b, void *r);
 int q_EVP_PKEY_cmp(const EVP_PKEY *a, const EVP_PKEY *b);
