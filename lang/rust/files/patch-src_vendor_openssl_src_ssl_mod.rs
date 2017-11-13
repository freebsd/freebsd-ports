--- src/vendor/openssl/src/ssl/mod.rs.orig	2017-10-09 21:52:52 UTC
+++ src/vendor/openssl/src/ssl/mod.rs
@@ -652,6 +652,7 @@ impl SslContextBuilder {
 
     /// Set the protocols to be used during Next Protocol Negotiation (the protocols
     /// supported by the application).
+    #[cfg(not(any(libressl261, libressl262, libressl263)))]
     pub fn set_npn_protocols(&mut self, protocols: &[&[u8]]) -> Result<(), ErrorStack> {
         // Firstly, convert the list of protocols to a byte-array that can be passed to OpenSSL
         // APIs -- a list of length-prefixed strings.
@@ -1310,6 +1311,7 @@ impl SslRef {
     ///
     /// The protocol's name is returned is an opaque sequence of bytes. It is up to the client
     /// to interpret it.
+    #[cfg(not(any(libressl261, libressl262, libressl263)))]
     pub fn selected_npn_protocol(&self) -> Option<&[u8]> {
         unsafe {
             let mut data: *const c_uchar = ptr::null();
