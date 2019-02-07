--- lib/vtls/openssl.c.orig	2019-02-05 14:00:12 UTC
+++ lib/vtls/openssl.c
@@ -3785,7 +3785,11 @@ static size_t Curl_ossl_version(char *bu
   unsigned long ssleay_value;
   sub[2]='\0';
   sub[1]='\0';
+#ifdef LIBRESSL_VERSION_NUMBER
+  ssleay_value = LIBRESSL_VERSION_NUMBER;
+#else
   ssleay_value = OpenSSL_version_num();
+#endif
   if(ssleay_value < 0x906000) {
     ssleay_value = SSLEAY_VERSION_NUMBER;
     sub[0]='\0';
