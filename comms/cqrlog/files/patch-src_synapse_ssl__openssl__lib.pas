--- src/synapse/ssl_openssl_lib.pas.orig	2018-07-11 04:13:02 UTC
+++ src/synapse/ssl_openssl_lib.pas
@@ -1875,23 +1875,12 @@ begin
 
   Paths := TStringList.Create;
   try
-    Paths.Add('/usr/lib64/');
-    Paths.Add('/lib64/');
-    Paths.Add('/usr/lib/x86_64-linux-gnu/');
-    Paths.Add('/lib/x86_64-linux-gnu/');
-    Paths.Add('/usr/lib/i386-linux-gnu/');
-    Paths.Add('/lib/i386-linux-gnu/');
+    Paths.Add('%%OPENSSLLIB%%');
     Paths.Add('/usr/lib/');
     Paths.Add('/lib/');
 
-    DLLSSLName  := MyFindFile('libssl*1.0.*', Paths);
-    DLLUtilName := MyFindFile('libcrypto*1.0.*', Paths);
-
-    if (DLLSSLName = '') then
-    begin
-      DLLSSLName  := MyFindFile('libssl*1.1*', Paths);
-      DLLUtilName := MyFindFile('libcrypto*1.1*', Paths)
-    end
+    DLLSSLName  := MyFindFile('libssl.so', Paths);
+    DLLUtilName := MyFindFile('libcrypto.so', Paths)
   finally
     FreeAndNil(Paths)
   end;
