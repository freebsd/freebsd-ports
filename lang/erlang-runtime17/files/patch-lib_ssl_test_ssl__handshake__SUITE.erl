
$FreeBSD$

--- lib/ssl/test/ssl_handshake_SUITE.erl.orig
+++ lib/ssl/test/ssl_handshake_SUITE.erl
@@ -39,6 +39,7 @@
 	  decode_unknown_hello_extension_correctly,
 	  encode_single_hello_sni_extension_correctly,
 	  decode_single_hello_sni_extension_correctly,
+	  decode_empty_server_sni_correctly,
 	  select_proper_tls_1_2_rsa_default_hashsign].
 
 %%--------------------------------------------------------------------
@@ -106,6 +107,13 @@
     Decoded = ssl_handshake:decode_hello_extensions(SNI),
     Exts = Decoded.
 
+decode_empty_server_sni_correctly(_Config) ->
+    Exts = #hello_extensions{sni = ""},
+    SNI = <<?UINT16(?SNI_EXT),?UINT16(0)>>,
+    Decoded = ssl_handshake:decode_hello_extensions(SNI),
+    Exts = Decoded.
+
+
 select_proper_tls_1_2_rsa_default_hashsign(_Config) ->
     % RFC 5246 section 7.4.1.4.1 tells to use {sha1,rsa} as default signature_algorithm for RSA key exchanges
     {sha, rsa} = ssl_handshake:select_hashsign_algs(undefined, ?rsaEncryption, {3,3}),
