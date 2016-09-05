--- rexxcurl.c.orig	2015-04-11 22:53:39 UTC
+++ rexxcurl.c
@@ -53,6 +53,8 @@
  * internal error                   set                 N/A
  * cURL runtime errors              -1                  set
  */
+#pragma clang diagnostic ignored "-Wincompatible-pointer-types-discards-qualifiers"
+
 #ifdef HAVE_CONFIG_H
 # include "config.h"
 #else
@@ -1366,7 +1368,7 @@ void RexxCURLSetVersionInfoConstants( Rx
    valuelen = 0;
    namelen = sprintf( name, "%sLIBSSH_VERSION", RxGetConstantPrefix( RxPackageGlobalData ) );
 #if LIBCURL_VERSION_NUM >= 0x071001
-   support = version_info->libssh_version;
+   support = (char *) version_info->libssh_version;
    valuelen = (version_info->libssh_version) ? strlen( version_info->libssh_version ) : 0;
 #endif
    SetRexxVariable( RxPackageGlobalData, name, namelen, support, valuelen );
@@ -1841,9 +1843,9 @@ int rexxcurl_sshkey_callback( CURL *easy
       if ( argv == NULL )
          return -1;
 
-      rx_knownkeylength_len = sprintf( rx_knownkeylength, "%lu", knownkey->len );
+      rx_knownkeylength_len = sprintf( rx_knownkeylength, "%lu", (unsigned long) knownkey->len );
       rx_knownkeytype_len = sprintf( rx_knownkeytype, "%u", knownkey->keytype );
-      rx_foundkeylength_len = sprintf( rx_foundkeylength, "%lu", foundkey->len );
+      rx_foundkeylength_len = sprintf( rx_foundkeylength, "%lu", (unsigned long) foundkey->len );
       rx_foundkeytype_len = sprintf( rx_foundkeytype, "%u", foundkey->keytype );
       rx_libcurlviewofkey_len = sprintf( rx_libcurlviewofkey, "%u", match );
 
