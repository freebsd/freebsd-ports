--- sql-common/client.c.orig	2018-01-17 11:39:51.315029000 +0000
+++ sql-common/client.c	2018-01-17 11:44:53.493273000 +0000
@@ -1884,7 +1884,7 @@
     *errptr= "Failed to get DNS name from SAN list item";
     DBUG_RETURN(1);
   }
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   cn= (const char *)ASN1_STRING_data(dns_name);
 #else
   cn= (const char *)ASN1_STRING_get0_data(dns_name);
@@ -1946,7 +1946,7 @@
     *errptr= "Invalid IP address embedded in the certificate SAN IP address";
     DBUG_RETURN(1);
   }
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   ip= ASN1_STRING_data(ip_address);
 #else
   ip= ASN1_STRING_get0_data(ip_address);
@@ -2111,7 +2111,7 @@
   if(server_ip_address != NULL)
   {
     iplen= ASN1_STRING_length(server_ip_address);
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     ipout= (const unsigned char *) ASN1_STRING_data(server_ip_address);
 #else
     ipout= (const unsigned char *) ASN1_STRING_get0_data(server_ip_address);
@@ -2163,7 +2163,7 @@
       goto error;
     }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     cn= (const char *) ASN1_STRING_data(cn_asn1);
 #else
     cn= (const char *) ASN1_STRING_get0_data(cn_asn1);
