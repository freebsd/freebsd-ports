--- src/vendor/openssl/src/ssl/tests/mod.rs.orig	2017-10-09 23:52:52.000000000 +0200
+++ src/vendor/openssl/src/ssl/tests/mod.rs	2017-11-09 13:42:46.721625000 +0100
@@ -503,6 +503,7 @@
 /// Tests that connecting with the client using NPN, but the server not does not
 /// break the existing connection behavior.
 #[test]
+#[cfg(not(any(libressl261, libressl262, libressl263)))]
 fn test_connect_with_unilateral_npn() {
     let (_s, stream) = Server::new();
     let mut ctx = SslContext::builder(SslMethod::tls()).unwrap();
@@ -615,6 +616,7 @@
 /// Tests that when the `SslStream` is created as a server stream, the protocols
 /// are correctly advertised to the client.
 #[test]
+#[cfg(not(any(libressl261, libressl262, libressl263)))]
 fn test_npn_server_advertise_multiple() {
     let listener = TcpListener::bind("127.0.0.1:0").unwrap();
     let localhost = listener.local_addr().unwrap();
@@ -1239,7 +1241,7 @@
 }
 
 #[test]
-#[cfg(any(all(feature = "v101", ossl101), all(feature = "v102", ossl102)))]
+#[cfg(any(all(feature = "v101", ossl101, not(any(libressl261, libressl262, libressl263))), all(feature = "v102", ossl102)))]
 fn tmp_ecdh_callback() {
     use ec::EcKey;
     use nid;
@@ -1306,7 +1308,7 @@
 }
 
 #[test]
-#[cfg(any(all(feature = "v101", ossl101), all(feature = "v102", ossl102)))]
+#[cfg(any(all(feature = "v101", ossl101, not(any(libressl261, libressl262, libressl263))), all(feature = "v102", ossl102)))]
 fn tmp_ecdh_callback_ssl() {
     use ec::EcKey;
     use nid;
