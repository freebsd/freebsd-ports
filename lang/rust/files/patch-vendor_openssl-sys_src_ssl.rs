--- vendor/openssl-sys/src/ssl.rs.orig	2019-05-13 21:50:35 UTC
+++ vendor/openssl-sys/src/ssl.rs
@@ -1032,7 +1032,7 @@ extern "C" {
 }
 
 cfg_if! {
-    if #[cfg(ossl110)] {
+    if #[cfg(any(ossl110, libressl291))] {
         extern "C" {
             pub fn TLS_method() -> *const SSL_METHOD;
 
