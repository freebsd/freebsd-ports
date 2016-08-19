--- rexxcurl.c.orig	2012-04-26 09:56:03 UTC
+++ rexxcurl.c
@@ -384,7 +384,9 @@ static curl_options RexxCurlOptions[] =
 #if LIBCURL_VERSION_NUM >= 0x071301
    { "CERTINFO"        ,CURLOPT_CERTINFO        ,RXCURLOPT_LONG        , NULL },
 #endif
+#if 0
    { "CLOSEPOLICY"     ,CURLOPT_CLOSEPOLICY     ,RXCURLOPT_POLICY      , NULL },
+#endif
 #if LIBCURL_VERSION_NUM >= 0x070f02
    { "CONNECTONLY"     ,CURLOPT_CONNECT_ONLY    ,RXCURLOPT_LONG        , NULL },
 #endif
@@ -489,8 +491,13 @@ static curl_options RexxCurlOptions[] =
    { "GSSAPIDELEGATION",CURLOPT_GSSAPI_DELEGATION,RXCURLOPT_GSSAPI_DELEGATION , NULL },
 #endif
    { "HEADER"          ,CURLOPT_HEADER          ,RXCURLOPT_BOOL        , NULL },
+#if LIBCURL_VERSION_NUM >= 0x070907
+   { "HEADERFILE"      ,CURLOPT_HEADERDATA      ,RXCURLOPT_OUTFILE     , NULL },
+   { "HEADERSTEM"      ,CURLOPT_HEADERDATA      ,RXCURLOPT_HEADERSTEM  , NULL },
+#else
    { "HEADERFILE"      ,CURLOPT_WRITEHEADER     ,RXCURLOPT_OUTFILE     , NULL },
    { "HEADERSTEM"      ,CURLOPT_WRITEHEADER     ,RXCURLOPT_HEADERSTEM  , NULL },
+#endif
 #if LIBCURL_VERSION_NUM >= 0x070a03
    { "HTTP200ALIASES"  ,CURLOPT_HTTP200ALIASES  ,RXCURLOPT_LIST        , NULL },
 #endif
@@ -517,9 +524,17 @@ static curl_options RexxCurlOptions[] =
 #if LIBCURL_VERSION_NUM >= 0x070e01
    { "IGNORECONTENTLENGTH",CURLOPT_IGNORE_CONTENT_LENGTH,RXCURLOPT_LONG, NULL },
 #endif
+#if LIBCURL_VERSION_NUM >= 0x070907
+   { "INFILE"          ,CURLOPT_READDATA        ,RXCURLOPT_INFILE      , NULL },
+#else
    { "INFILE"          ,CURLOPT_INFILE          ,RXCURLOPT_INFILE      , NULL },
+#endif
    { "INTERFACE"       ,CURLOPT_INTERFACE       ,RXCURLOPT_STRING      , NULL },
+#if LIBCURL_VERSION_NUM >= 0x070907
+   { "INSTEM"          ,CURLOPT_READDATA        ,RXCURLOPT_INSTEM      , NULL },
+#else
    { "INSTEM"          ,CURLOPT_INFILE          ,RXCURLOPT_INSTEM      , NULL },
+#endif
 #if LIBCURL_VERSION_NUM >= 0x070a08
    { "IPRESOLVE"       ,CURLOPT_IPRESOLVE       ,RXCURLOPT_IPRESOLVE   , NULL },
 #endif
@@ -576,8 +591,10 @@ static curl_options RexxCurlOptions[] =
 #if LIBCURL_VERSION_NUM >= 0x070a02
    { "NOSIGNAL"        ,CURLOPT_NOSIGNAL        ,RXCURLOPT_BOOL        , NULL },
 #endif
-   { "OUTFILE"         ,CURLOPT_FILE            ,RXCURLOPT_OUTFILE     , NULL },
-   { "OUTSTEM"         ,CURLOPT_FILE            ,RXCURLOPT_OUTSTEM     , NULL },
+#if LIBCURL_VERSION_NUM >= 0x070907
+   { "OUTFILE"         ,CURLOPT_WRITEDATA       ,RXCURLOPT_OUTFILE     , NULL },
+   { "OUTSTEM"         ,CURLOPT_WRITEDATA       ,RXCURLOPT_OUTSTEM     , NULL },
+#endif
 #if LIBCURL_VERSION_NUM >= 0x071301
    { "PASSWORD"        ,CURLOPT_PASSWORD        ,RXCURLOPT_STRING      , NULL },
 #endif
@@ -1269,7 +1286,7 @@ void RexxCURLSetVersionInfoConstants( Rx
    valuelen = 0;
    namelen = sprintf( name, "%sLIBSSH_VERSION", RxGetConstantPrefix( RxPackageGlobalData ) );
 #if LIBCURL_VERSION_NUM >= 0x071001
-   support = version_info->libssh_version;
+   support = (char *) version_info->libssh_version;
    valuelen = (version_info->libssh_version) ? strlen( version_info->libssh_version ) : 0;
 #endif
    SetRexxVariable( RxPackageGlobalData, name, namelen, support, valuelen );
@@ -2273,9 +2290,10 @@ rxfunc( CurlSetopt )
             SetCURLError( RxPackageGlobalData,  curl_rc, curl_errors[rc] );
             break;
          }
+#if LIBCURL_VERSION_NUMBER > 0x070907
          switch ( RexxCurlOptions[opt].number )
          {
-            case CURLOPT_FILE:
+            case CURLOPT_WRITEDATA:
                if ( argv[2].strlength )
                {
                   /*
@@ -2293,6 +2311,7 @@ rxfunc( CurlSetopt )
             default:
                break;
          }
+#endif
          break;
       case RXCURLOPT_INFILE:
          /* parameter must be the name of a file to read from or blank to turn it off */
@@ -2317,7 +2336,11 @@ rxfunc( CurlSetopt )
           */
          switch ( RexxCurlOptions[opt].number )
          {
+#if LIBCURL_VERSION_NUM >= 0x070907
+            case CURLOPT_READDATA:
+#else
             case CURLOPT_INFILE:
+#endif
                /*
                 * Always set the file size for the specified INFILE
                 */
