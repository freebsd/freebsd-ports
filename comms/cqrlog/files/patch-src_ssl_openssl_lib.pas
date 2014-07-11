--- src/ssl_openssl_lib.pas.orig	2014-06-30 22:02:45.000000000 -0700
+++ src/ssl_openssl_lib.pas	2014-06-30 22:04:17.000000000 -0700
@@ -86,7 +86,7 @@
 
 {$IFDEF CIL}
 const
-  {$IFDEF LINUX}
+  {$IFNDEF WIN32}
   DLLSSLName = 'libssl.so';
   DLLUtilName = 'libcrypto.so';
   {$ELSE}
@@ -1704,7 +1704,7 @@
 {$ELSE}
       SSLLibHandle := LoadLib(DLLSSLName);
       SSLUtilHandle := LoadLib(DLLUtilName);
-  {$IFNDEF LINUX}
+  {$IFDEF WIN32}
       if (SSLLibHandle = 0) then
         SSLLibHandle := LoadLib(DLLSSLName2);
   {$ENDIF}
