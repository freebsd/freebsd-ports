--- src/libneon/src/ne_openssl.c.orig	2006-07-20 06:34:38 UTC
+++ src/libneon/src/ne_openssl.c
@@ -84,17 +84,17 @@ char *ne_ssl_readable_dname(const ne_ssl_dname *name)
 	
         /* Skip commonName or emailAddress except if there is no other
          * attribute in dname. */
-	if ((OBJ_cmp(ent->object, cname) && OBJ_cmp(ent->object, email)) ||
+	if ((OBJ_cmp(X509_NAME_ENTRY_get_object(ent), cname) && OBJ_cmp(X509_NAME_ENTRY_get_object(ent), email)) ||
             (!flag && n == 1)) {
  	    if (flag++)
 		ne_buffer_append(dump, ", ", 2);
 
-            switch (ent->value->type) {
+            switch (X509_NAME_ENTRY_get_data(ent)->type) {
             case V_ASN1_UTF8STRING:
             case V_ASN1_IA5STRING: /* definitely ASCII */
             case V_ASN1_VISIBLESTRING: /* probably ASCII */
             case V_ASN1_PRINTABLESTRING: /* subset of ASCII */
-                ne_buffer_append(dump, ent->value->data, ent->value->length);
+                ne_buffer_append(dump, X509_NAME_ENTRY_get_data(ent)->data, X509_NAME_ENTRY_get_data(ent)->length);
                 break;
             case V_ASN1_UNIVERSALSTRING:
             case V_ASN1_T61STRING: /* let OpenSSL convert it as ISO-8859-1 */
@@ -102,7 +102,7 @@ char *ne_ssl_readable_dname(const ne_ssl_dname *name)
                 unsigned char *tmp = ""; /* initialize to workaround 0.9.6 bug */
                 int len;
 
-                len = ASN1_STRING_to_UTF8(&tmp, ent->value);
+                len = ASN1_STRING_to_UTF8(&tmp, X509_NAME_ENTRY_get_data(ent));
                 if (len > 0) {
                     ne_buffer_append(dump, tmp, len);
                     OPENSSL_free(tmp);
@@ -425,8 +425,13 @@ static ne_ssl_client_cert *dup_client_cert(const ne_ss
 
     populate_cert(&newcc->cert, cc->cert.subject);
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     cc->cert.subject->references++;
     cc->pkey->references++;
+#else
+    X509_up_ref(cc->cert.subject);
+    EVP_PKEY_up_ref(cc->pkey);
+#endif
     return newcc;
 }
 
@@ -465,8 +470,13 @@ static int provide_client_cert(SSL *ssl, X509 **cert, 
     if (sess->client_cert) {
         ne_ssl_client_cert *const cc = sess->client_cert;
 	NE_DEBUG(NE_DBG_SSL, "Supplying client certificate.\n");
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	cc->pkey->references++;
 	cc->cert.subject->references++;
+#else
+	EVP_PKEY_up_ref(cc->pkey);
+	X509_up_ref(cc->cert.subject);
+#endif
 	*cert = cc->cert.subject;
 	*pkey = cc->pkey;
 	return 1;
