--- rexxcurl.c.orig	2019-02-10 22:51:41 UTC
+++ rexxcurl.c
@@ -52,6 +52,8 @@
  * internal error                   set                 N/A
  * cURL runtime errors              -1                  set
  */
+#pragma clang diagnostic ignored "-Wincompatible-pointer-types-discards-qualifiers"
+
 #ifdef HAVE_CONFIG_H
 # include "config.h"
 #else
@@ -480,8 +482,13 @@ static curl_options RexxCurlOptions[] =
    { "FTPLISTONLY"     ,CURLOPT_FTPLISTONLY     ,RXCURLOPT_BOOL        , NULL },
 #endif
    { "FTPPORT"         ,CURLOPT_FTPPORT         ,RXCURLOPT_STRING      , NULL },
+#if LIBCURL_VERSION_NUM >= 0x075500
+   { "FTPRESPONSETIMEOUT", CURLOPT_SERVER_RESPONSE_TIMEOUT, RXCURLOPT_LONG, NULL },
+#endif
 #if LIBCURL_VERSION_NUM >= 0x070a08
+# if LIBCURL_VERSION_NUM < 0x075500
    { "FTPRESPONSETIMEOUT", CURLOPT_FTP_RESPONSE_TIMEOUT, RXCURLOPT_LONG, NULL },
+# endif
 #endif
 #if LIBCURL_VERSION_NUM >= 0x070e00
    { "FTPSKIPPASVIP"   ,CURLOPT_FTP_SKIP_PASV_IP,RXCURLOPT_BOOL        , NULL },
@@ -1879,9 +1886,9 @@ int rexxcurl_sshkey_callback( CURL *easy,     /* easy 
       if ( argv == NULL )
          return -1;
 
-      rx_knownkeylength_len = sprintf( rx_knownkeylength, "%lu", knownkey->len );
+      rx_knownkeylength_len = sprintf( rx_knownkeylength, "%lu", (unsigned long) knownkey->len );
       rx_knownkeytype_len = sprintf( rx_knownkeytype, "%u", knownkey->keytype );
-      rx_foundkeylength_len = sprintf( rx_foundkeylength, "%lu", foundkey->len );
+      rx_foundkeylength_len = sprintf( rx_foundkeylength, "%lu", (unsigned long) foundkey->len );
       rx_foundkeytype_len = sprintf( rx_foundkeytype, "%u", foundkey->keytype );
       rx_libcurlviewofkey_len = sprintf( rx_libcurlviewofkey, "%u", match );
 
@@ -1964,11 +1971,11 @@ int debug_function( CURL *handle, curl_infotype type, 
    int c;
    char *prefix = "*<><><>";
    if ( type == CURLINFO_TEXT )
-      fprintf( fp, "text: %c %.*s", prefix[type],size, data );
+      fprintf( fp, "text: %c %.*s", prefix[type],(int)size, data );
    if ( type == CURLINFO_HEADER_IN )
-      fprintf( fp, "header_in: %c %.*s", prefix[type],size, data );
+      fprintf( fp, "header_in: %c %.*s", prefix[type],(int)size, data );
    if ( type == CURLINFO_HEADER_OUT )
-      fprintf( fp, "header_out:%c %.*s", prefix[type],size, data );
+      fprintf( fp, "header_out:%c %.*s", prefix[type],(int)size, data );
    if ( type == CURLINFO_SSL_DATA_IN )
    {
       fprintf( fp, "ssl_data_in: " );
