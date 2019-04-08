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
@@ -1879,9 +1881,9 @@ int rexxcurl_sshkey_callback( CURL *easy
       if ( argv == NULL )
          return -1;
 
-      rx_knownkeylength_len = sprintf( rx_knownkeylength, "%lu", knownkey->len );
+      rx_knownkeylength_len = sprintf( rx_knownkeylength, "%lu", (unsigned long) knownkey->len );
       rx_knownkeytype_len = sprintf( rx_knownkeytype, "%u", knownkey->keytype );
-      rx_foundkeylength_len = sprintf( rx_foundkeylength, "%lu", foundkey->len );
+      rx_foundkeylength_len = sprintf( rx_foundkeylength, "%lu", (unsigned long) foundkey->len );
       rx_foundkeytype_len = sprintf( rx_foundkeytype, "%u", foundkey->keytype );
       rx_libcurlviewofkey_len = sprintf( rx_libcurlviewofkey, "%u", match );
 
@@ -1964,11 +1966,11 @@ int debug_function( CURL *handle, curl_i
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
