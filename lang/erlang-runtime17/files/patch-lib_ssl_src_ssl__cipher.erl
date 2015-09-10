--- lib/ssl/src/ssl_cipher.erl.orig	2015-03-31 12:32:52 UTC
+++ lib/ssl/src/ssl_cipher.erl
@@ -1209,7 +1209,8 @@ hash_algorithm(?SHA) -> sha;
 hash_algorithm(?SHA224) -> sha224;
 hash_algorithm(?SHA256) -> sha256;
 hash_algorithm(?SHA384) -> sha384;
-hash_algorithm(?SHA512) -> sha512.
+hash_algorithm(?SHA512) -> sha512;
+hash_algorithm(Other) when is_integer(Other) andalso ((Other >= 224) and (Other =< 255)) -> Other.
 
 sign_algorithm(anon)  -> ?ANON;
 sign_algorithm(rsa)   -> ?RSA;
@@ -1218,7 +1219,8 @@ sign_algorithm(ecdsa) -> ?ECDSA;
 sign_algorithm(?ANON) -> anon;
 sign_algorithm(?RSA) -> rsa;
 sign_algorithm(?DSA) -> dsa;
-sign_algorithm(?ECDSA) -> ecdsa.
+sign_algorithm(?ECDSA) -> ecdsa;
+sign_algorithm(Other) when is_integer(Other) andalso ((Other >= 224) and (Other =< 255)) -> Other.
 
 hash_size(null) ->
     0;
