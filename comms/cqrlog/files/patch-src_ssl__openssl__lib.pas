--- src/ssl_openssl_lib.pas.orig	2016-04-20 16:06:15 UTC
+++ src/ssl_openssl_lib.pas
@@ -86,7 +86,7 @@ uses
 
 {$IFDEF CIL}
 const
-  {$IFDEF LINUX}
+  {$IFNDEF WIN32}
   DLLSSLName = 'libssl.so';
   DLLUtilName = 'libcrypto.so';
   {$ELSE}
@@ -1704,7 +1704,7 @@ begin
 {$ELSE}
       SSLLibHandle := LoadLib(DLLSSLName);
       SSLUtilHandle := LoadLib(DLLUtilName);
-  {$IFNDEF LINUX}
+  {$IFDEF WIN32}
       if (SSLLibHandle = 0) then
         SSLLibHandle := LoadLib(DLLSSLName2);
   {$ENDIF}
