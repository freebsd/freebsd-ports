--- vendor/openssl/src/version.rs.orig	2019-05-13 21:50:34 UTC
+++ vendor/openssl/src/version.rs
@@ -14,7 +14,7 @@
 use std::ffi::CStr;
 
 cfg_if! {
-    if #[cfg(ossl110)] {
+    if #[cfg(any(ossl110, libressl271))] {
         use ffi::{
             OPENSSL_VERSION, OPENSSL_CFLAGS, OPENSSL_BUILT_ON, OPENSSL_PLATFORM, OPENSSL_DIR,
             OpenSSL_version_num, OpenSSL_version,
