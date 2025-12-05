--- cargo-crates/openssl-sys-0.9.61/src/ssl.rs.orig2021-01-01 00:00:00 UTC
+++ cargo-crates/openssl-sys-0.9.61/src/ssl.rs
@@ -982,7 +982,12 @@
         len: c_long,
     ) -> *mut SSL_SESSION;
 
+    #[cfg(ossl300)]
+    #[link_name = "SSL_get1_peer_certificate"]
+    pub fn SSL_get_peer_certificate(ssl: *const SSL) -> *mut X509;
+    #[cfg(not(ossl300))]
     pub fn SSL_get_peer_certificate(ssl: *const SSL) -> *mut X509;
+
 
     pub fn SSL_get_peer_cert_chain(ssl: *const SSL) -> *mut stack_st_X509;
 
