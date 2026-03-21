https://github.com/openbsd/ports/blob/master/lang/php/8.4/patches/patch-ext_openssl_openssl_c

--- ext/openssl/openssl.c.orig	2026-03-10 15:51:04 UTC
+++ ext/openssl/openssl.c
@@ -2308,7 +2308,7 @@ static STACK_OF(X509) *php_openssl_load_all_certs_from
 		goto end;
 	}
 
-	if(!(stack = sk_X509_new_reserve(NULL, sk_X509_INFO_num(sk)))) {
+	if(!(stack = sk_X509_new_null())) {
 		php_openssl_store_errors();
 		goto end;
 	}
@@ -2317,7 +2317,11 @@ static STACK_OF(X509) *php_openssl_load_all_certs_from
 	while (sk_X509_INFO_num(sk)) {
 		xi=sk_X509_INFO_shift(sk);
 		if (xi->x509 != NULL) {
-			sk_X509_push(stack,xi->x509);
+			if(sk_X509_push(stack,xi->x509) == 0) {
+				php_error_docref(NULL, E_ERROR, "Memory allocation failure");
+				sk_X509_pop_free(stack,X509_free);
+				goto end;
+			}
 			xi->x509=NULL;
 		}
 		X509_INFO_free(xi);
@@ -3828,7 +3832,7 @@ static EVP_PKEY * php_openssl_generate_private_key(str
 /* {{{ php_openssl_generate_private_key */
 static EVP_PKEY * php_openssl_generate_private_key(struct php_x509_request * req)
 {
-	if (req->priv_key_bits < MIN_KEY_LENGTH) {
+	if (req->priv_key_type != OPENSSL_KEYTYPE_EC && req->priv_key_bits < MIN_KEY_LENGTH) {
 		php_error_docref(NULL, E_WARNING, "Private key length must be at least %d bits, configured to %d",
 			MIN_KEY_LENGTH, req->priv_key_bits);
 		return NULL;
