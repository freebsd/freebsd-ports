--- ssl.c.orig	2018-11-05 23:29:01 UTC
+++ ssl.c
@@ -872,8 +872,11 @@ lms_ssl_store *_lms_ssl_loadfiles(X509 *
 	 * dhp = DH params
 	 */
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000
+    ks->ca = X509_dup(ca);
+#else
 	memcpy(ks->ca, ca, sizeof(X509));
-
+#endif
 	ks->crt = X509_new();
 	ks->privkey = RSA_new();
 	ks->pubkey = RSA_new();
