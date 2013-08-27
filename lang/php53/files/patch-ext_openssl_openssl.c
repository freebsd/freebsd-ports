diff --git a/ext/openssl/openssl.c b/ext/openssl/openssl.c
index d7ac117..c32748c 100644
--- ext/openssl/openssl.c
+++ ext/openssl/openssl.c
@@ -1398,6 +1398,74 @@ PHP_FUNCTION(openssl_x509_check_private_key)
 }
 /* }}} */
 
+/* Special handling of subjectAltName, see CVE-2013-4073
+ * Christian Heimes
+ */
+
+static int openssl_x509v3_subjectAltName(BIO *bio, X509_EXTENSION *extension)
+{
+	GENERAL_NAMES *names;
+	const X509V3_EXT_METHOD *method = NULL;
+	long i, length, num;
+	const unsigned char *p;
+
+	method = X509V3_EXT_get(extension);
+	if (method == NULL) {
+		return -1;
+	}
+
+	p = extension->value->data;
+	length = extension->value->length;
+	if (method->it) {
+		names = (GENERAL_NAMES*)(ASN1_item_d2i(NULL, &p, length,
+						       ASN1_ITEM_ptr(method->it)));
+	} else {
+		names = (GENERAL_NAMES*)(method->d2i(NULL, &p, length));
+	}
+	if (names == NULL) {
+		return -1;
+	}
+
+	num = sk_GENERAL_NAME_num(names);
+	for (i = 0; i < num; i++) {
+			GENERAL_NAME *name;
+			ASN1_STRING *as;
+			name = sk_GENERAL_NAME_value(names, i);
+			switch (name->type) {
+				case GEN_EMAIL:
+					BIO_puts(bio, "email:");
+					as = name->d.rfc822Name;
+					BIO_write(bio, ASN1_STRING_data(as),
+						  ASN1_STRING_length(as));
+					break;
+				case GEN_DNS:
+					BIO_puts(bio, "DNS:");
+					as = name->d.dNSName;
+					BIO_write(bio, ASN1_STRING_data(as),
+						  ASN1_STRING_length(as));
+					break;
+				case GEN_URI:
+					BIO_puts(bio, "URI:");
+					as = name->d.uniformResourceIdentifier;
+					BIO_write(bio, ASN1_STRING_data(as),
+						  ASN1_STRING_length(as));
+					break;
+				default:
+					/* use builtin print for GEN_OTHERNAME, GEN_X400,
+					 * GEN_EDIPARTY, GEN_DIRNAME, GEN_IPADD and GEN_RID
+					 */
+					GENERAL_NAME_print(bio, name);
+			}
+			/* trailing ', ' except for last element */
+			if (i < (num - 1)) {
+				BIO_puts(bio, ", ");
+			}
+	}
+	sk_GENERAL_NAME_pop_free(names, GENERAL_NAME_free);
+
+	return 0;
+}
+
 /* {{{ proto array openssl_x509_parse(mixed x509 [, bool shortnames=true])
    Returns an array of the fields/values of the CERT */
 PHP_FUNCTION(openssl_x509_parse)
@@ -1494,15 +1562,29 @@ PHP_FUNCTION(openssl_x509_parse)
 
 
 	for (i = 0; i < X509_get_ext_count(cert); i++) {
+		int nid;
 		extension = X509_get_ext(cert, i);
-		if (OBJ_obj2nid(X509_EXTENSION_get_object(extension)) != NID_undef) {
+		nid = OBJ_obj2nid(X509_EXTENSION_get_object(extension));
+		if (nid != NID_undef) {
 			extname = (char *)OBJ_nid2sn(OBJ_obj2nid(X509_EXTENSION_get_object(extension)));
 		} else {
 			OBJ_obj2txt(buf, sizeof(buf)-1, X509_EXTENSION_get_object(extension), 1);
 			extname = buf;
 		}
 		bio_out = BIO_new(BIO_s_mem());
-		if (X509V3_EXT_print(bio_out, extension, 0, 0)) {
+		if (nid == NID_subject_alt_name) {
+			if (openssl_x509v3_subjectAltName(bio_out, extension) == 0) {
+				add_assoc_stringl(subitem, extname, bio_buf->data, bio_buf->length, 1);
+			} else {
+				zval_dtor(return_value);
+				if (certresource == -1 && cert) {
+					X509_free(cert);
+				}
+				BIO_free(bio_out);
+				RETURN_FALSE;
+			}
+		}
+		else if (X509V3_EXT_print(bio_out, extension, 0, 0)) {
 			BIO_get_mem_ptr(bio_out, &bio_buf);
 			add_assoc_stringl(subitem, extname, bio_buf->data, bio_buf->length, 1);
 		} else {
