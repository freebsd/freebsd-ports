--- src/vendor/openssl/src/ssl/tests/mod.rs.orig	2017-10-10 20:21:13 UTC
+++ src/vendor/openssl/src/ssl/tests/mod.rs
@@ -564,6 +564,7 @@ fn test_connect_with_unilateral_alpn() {
 /// Tests that connecting with the client using NPN, but the server not does not
 /// break the existing connection behavior.
 #[test]
+#[cfg(not(any(libressl261, libressl262)))]
 fn test_connect_with_unilateral_npn() {
     let (_s, stream) = Server::new();
     let mut ctx = SslContext::builder(SslMethod::tls()).unwrap();
@@ -676,6 +677,7 @@ fn test_connect_with_npn_successful_single_match() {
 /// Tests that when the `SslStream` is created as a server stream, the protocols
 /// are correctly advertised to the client.
 #[test]
+#[cfg(not(any(libressl261, libressl262)))]
 fn test_npn_server_advertise_multiple() {
     let listener = TcpListener::bind("127.0.0.1:0").unwrap();
     let localhost = listener.local_addr().unwrap();
@@ -1311,7 +1313,7 @@ fn tmp_dh_callback() {
 }
 
 #[test]
-#[cfg(any(all(feature = "v101", ossl101), all(feature = "v102", ossl102)))]
+#[cfg(any(all(feature = "v101", ossl101, not(any(libressl261, libressl262))), all(feature = "v102", ossl102)))]
 fn tmp_ecdh_callback() {
     use ec::EcKey;
     use nid;
@@ -1378,7 +1380,7 @@ fn tmp_dh_callback_ssl() {
 }
 
 #[test]
-#[cfg(any(all(feature = "v101", ossl101), all(feature = "v102", ossl102)))]
+#[cfg(any(all(feature = "v101", ossl101, not(any(libressl261, libressl262))), all(feature = "v102", ossl102)))]
 fn tmp_ecdh_callback_ssl() {
     use ec::EcKey;
     use nid;
