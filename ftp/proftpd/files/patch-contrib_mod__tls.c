--- contrib/mod_tls.c.orig	2017-01-16 01:13:01 UTC
+++ contrib/mod_tls.c
@@ -96,7 +96,7 @@ static DH *get_dh(BIGNUM *p, BIGNUM *g) 
     return NULL;
   }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
   if (DH_set0_pqg(dh, p, NULL, g) != 1) {
     pr_trace_msg(trace_channel, 3, "error setting DH p/q parameters: %s",
       ERR_error_string(ERR_get_error(), NULL));
@@ -114,7 +114,7 @@ static DH *get_dh(BIGNUM *p, BIGNUM *g) 
 static X509 *read_cert(FILE *fh, SSL_CTX *ssl_ctx) {
   X509 *cert;
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
   cert = PEM_read_X509(fh, NULL, SSL_CTX_get_default_passwd_cb(ssl_ctx),
     SSL_CTX_get_default_passwd_cb_userdata(ssl_ctx));
 #else
@@ -128,7 +128,7 @@ static X509 *read_cert(FILE *fh, SSL_CTX
 static int get_pkey_type(EVP_PKEY *pkey) {
   int pkey_type;
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
   pkey_type = EVP_PKEY_id(pkey);
 #else
   pkey_type = EVP_PKEY_type(pkey->type);
@@ -609,7 +609,7 @@ static void tls_diags_cb(const SSL *ssl,
         break;
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
       case TLS_ST_OK:
 #else
       case SSL_ST_OK:
@@ -633,7 +633,7 @@ static void tls_diags_cb(const SSL *ssl,
 
     ssl_state = SSL_get_state(ssl);
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     if (ssl_state == TLS_ST_SR_CLNT_HELLO) {
 #else
     if (ssl_state == SSL3_ST_SR_CLNT_HELLO_A ||
@@ -675,7 +675,7 @@ static void tls_diags_cb(const SSL *ssl,
       }
 
 #if OPENSSL_VERSION_NUMBER >= 0x009080cfL && \
-    OPENSSL_VERSION_NUMBER < 0x10100000L
+    (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
     } else if (ssl_state & SSL_ST_RENEGOTIATE) {
       if ((ssl == ctrl_ssl && !tls_ctrl_need_init_handshake) ||
           (ssl != ctrl_ssl && !tls_data_need_init_handshake)) {
@@ -2932,7 +2932,8 @@ static int tls_init_ctx(void) {
   }
 
   SSL_CTX_set_tmp_dh_callback(ssl_ctx, tls_dh_cb);
-#if defined(PR_USE_OPENSSL_ECC) && OPENSSL_VERSION_NUMBER < 0x10100000L
+#if defined(PR_USE_OPENSSL_ECC) && \
+	(OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
   SSL_CTX_set_tmp_ecdh_callback(ssl_ctx, tls_ecdh_cb);
 #endif /* PR_USE_OPENSSL_ECC */
 
@@ -4837,7 +4838,7 @@ static int tls_dotlogin_allow(const char
 
     pr_signals_handle();
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     X509_get0_signature(&client_sig, NULL, client_cert);
     X509_get0_signature(&file_sig, NULL, file_cert);
 #else
@@ -4845,7 +4846,7 @@ static int tls_dotlogin_allow(const char
     file_sig = file_cert->signature;
 #endif /* OpenSSL-1.1.x and later */
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     if (!ASN1_STRING_cmp(client_sig, file_sig)) {
 #else
     if (!M_ASN1_BIT_STRING_cmp(client_sig, file_sig)) {
@@ -5320,7 +5321,7 @@ static void tls_setup_cert_dn_environ(co
   int nentries;
   char *k, *v;
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
   nentries = X509_NAME_entry_count(name);
 #else
   nentries = sk_X509_NAME_ENTRY_num(name->entries);
@@ -5333,7 +5334,7 @@ static void tls_setup_cert_dn_environ(co
 
     pr_signals_handle();
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     entry = X509_NAME_get_entry(name, i);
     nid = OBJ_obj2nid(X509_NAME_ENTRY_get_object(entry));
     entry_data = ASN1_STRING_data(X509_NAME_ENTRY_get_data(entry));
@@ -5512,7 +5513,7 @@ static void tls_setup_cert_environ(const
     BIO_free(bio);
 
     bio = BIO_new(BIO_s_mem());
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     X509_get0_signature(NULL, &algo, cert);
 #else
     algo = cert->cert_info->signature;
@@ -5528,7 +5529,7 @@ static void tls_setup_cert_environ(const
     BIO_free(bio);
 
     bio = BIO_new(BIO_s_mem());
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     pubkey = X509_get_X509_PUBKEY(cert);
     X509_PUBKEY_get0_param(NULL, NULL, NULL, &algo, pubkey);
 #else
@@ -5587,7 +5588,7 @@ static void tls_setup_environ(SSL *ssl) 
       const unsigned char *sess_data;
       unsigned int sess_datalen;
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
       sess_data = SSL_SESSION_get_id(ssl_session, &sess_datalen);
 #else
       sess_datalen = ssl_session->session_id_length;
@@ -5738,7 +5739,7 @@ static int tls_verify_cb(int ok, X509_ST
     X509 *cert = X509_STORE_CTX_get_current_cert(ctx);
     int ctx_error, depth = X509_STORE_CTX_get_error_depth(ctx);
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     verify_err = X509_STORE_CTX_get_error(ctx);
 #else
     verify_err = ctx->error;
@@ -5755,7 +5756,7 @@ static int tls_verify_cb(int ok, X509_ST
       X509_STORE_CTX_set_error(ctx, X509_V_ERR_CERT_CHAIN_TOO_LONG);
     }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     ctx_error = X509_STORE_CTX_get_error(ctx);
 #else
     ctx_error = ctx->error;
@@ -5886,7 +5887,7 @@ static int tls_verify_crl(int ok, X509_S
   X509_STORE_CTX_init(store_ctx, tls_crl_store, NULL, NULL);
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
   crls = X509_STORE_CTX_get1_crls(store_ctx, subject);
 #elif OPENSSL_VERSION_NUMBER >= 0x10000000L
   crls = X509_STORE_get1_crls(store_ctx, subject);
@@ -5906,14 +5907,14 @@ static int tls_verify_crl(int ok, X509_S
       X509_NAME_print(b, issuer, 0);
 
       BIO_printf(b, ", lastUpdate: ");
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
       ASN1_UTCTIME_print(b, X509_CRL_get_lastUpdate(crl));
 #else
       ASN1_UTCTIME_print(b, crl->crl->lastUpdate);
 #endif /* OpenSSL-1.1.x and later */
 
       BIO_printf(b, ", nextUpdate: ");
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
       ASN1_UTCTIME_print(b, X509_CRL_get_nextUpdate(crl));
 #else
       ASN1_UTCTIME_print(b, crl->crl->nextUpdate);
@@ -5983,7 +5984,7 @@ static int tls_verify_crl(int ok, X509_S
    * the current certificate in order to check for revocation.
    */
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
   crls = X509_STORE_CTX_get1_crls(store_ctx, subject);
 #elif OPENSSL_VERSION_NUMBER >= 0x10000000L
   crls = X509_STORE_get1_crls(store_ctx, subject);
@@ -6005,7 +6006,7 @@ static int tls_verify_crl(int ok, X509_S
         ASN1_INTEGER *sn;
 
         revoked = sk_X509_REVOKED_value(X509_CRL_get_REVOKED(crl), i);
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
         sn = X509_REVOKED_get0_serialNumber(revoked);
 #else
         sn = revoked->serialNumber;
@@ -6371,7 +6372,7 @@ static int tls_verify_ocsp_url(X509_STOR
     return FALSE;
   }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
   store = X509_STORE_CTX_get0_store(ctx);
 #else
   store = ctx->ctx;
