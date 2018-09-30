--- src/vendor/openssl-sys/build/main.rs.orig	2018-09-11 04:49:55 UTC
+++ src/vendor/openssl-sys/build/main.rs
@@ -497,6 +497,7 @@ See rust-openssl README for more information:
             (6, 2) => ('6', '2'),
             (6, _) => ('6', 'x'),
             (7, _) => ('7', 'x'),
+            (8, _) => ('8', 'x'),
             _ => version_error(),
         };
 
@@ -537,7 +538,7 @@ fn version_error() -> ! {
         "
 
 This crate is only compatible with OpenSSL 1.0.1 through 1.1.1, or LibreSSL 2.5
-through 2.7, but a different version of OpenSSL was found. The build is now aborting
+through 2.8, but a different version of OpenSSL was found. The build is now aborting
 due to this version mismatch.
 
 "
