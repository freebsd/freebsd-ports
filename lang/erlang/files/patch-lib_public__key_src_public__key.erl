
$FreeBSD$

--- lib/public_key/src/public_key.erl.orig
+++ lib/public_key/src/public_key.erl
@@ -576,7 +576,7 @@
 %%--------------------------------------------------------------------
 pem_to_der(CertSource) ->
     {ok, Bin} = file:read_file(CertSource),
-    pubkey_pem:decode(Bin).
+    {ok, pubkey_pem:decode(Bin)}.
 
 decode_private_key(KeyInfo) ->
     decode_private_key(KeyInfo, no_passwd).
