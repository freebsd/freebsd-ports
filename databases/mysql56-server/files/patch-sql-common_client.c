--- sql-common/client.c.orig	2019-11-26 16:53:45 UTC
+++ sql-common/client.c
@@ -1980,7 +1980,11 @@ static int ssl_verify_server_cert(Vio *vio, const char
     goto error;
   }
 
-  cn= (char *) ASN1_STRING_data(cn_asn1);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+  cn= (const char *) ASN1_STRING_data(cn_asn1);
+#else
+  cn= (const char *) ASN1_STRING_get0_data(cn_asn1);
+#endif
 
   // There should not be any NULL embedded in the CN
   if ((size_t)ASN1_STRING_length(cn_asn1) != strlen(cn))
