--- ssl.c.orig	2021-08-02 06:24:35 UTC
+++ ssl.c
@@ -31,10 +31,10 @@
 #include <errno.h>
 #include <limits.h>
 
-static char* get_ssl_error();
+static char* get_ssl_error(void);
 static SSL* get_ssl(struct vsf_session* p_sess, int fd);
 static int ssl_session_init(struct vsf_session* p_sess);
-static void setup_bio_callbacks();
+static void setup_bio_callbacks(SSL* p_ssl);
 static long bio_callback(
   BIO* p_bio, int oper, const char* p_arg, int argi, long argl, long retval);
 static int ssl_verify_callback(int verify_ok, X509_STORE_CTX* p_ctx);
@@ -93,10 +93,12 @@ ssl_init(struct vsf_session* p_sess)
     {
       options |= SSL_OP_NO_TLSv1_2;
     }
+#ifdef SSL_OP_NO_TLSv1_3
     if (!tunable_tlsv1_3)
     {
       options |= SSL_OP_NO_TLSv1_3;
     }
+#endif
     SSL_CTX_set_options(p_ctx, options);
     if (tunable_rsa_cert_file)
     {
@@ -139,6 +141,7 @@ ssl_init(struct vsf_session* p_sess)
     {
       die("SSL: RNG is not seeded");
     }
+#if OPENSSL_VERSION_NUMBER < 0x10200000L
     {
       EC_KEY* key = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);
       if (key == NULL)
@@ -148,6 +151,7 @@ ssl_init(struct vsf_session* p_sess)
       SSL_CTX_set_tmp_ecdh(p_ctx, key);
       EC_KEY_free(key);
     }
+#endif
     if (tunable_ssl_request_cert)
     {
       verify_option |= SSL_VERIFY_PEER;
@@ -683,7 +687,7 @@ ssl_cert_digest(SSL* p_ssl, struct vsf_session* p_sess
 }
 
 static char*
-get_ssl_error()
+get_ssl_error(void)
 {
   SSL_load_error_strings();
   return ERR_error_string(ERR_get_error(), NULL);
