--- vendor/openssl-sys/build/main.rs.orig	2021-11-29 20:27:34 UTC
+++ vendor/openssl-sys/build/main.rs
@@ -237,6 +237,7 @@ See rust-openssl README for more information:
             (3, 3, 0) => ('3', '3', '0'),
             (3, 3, 1) => ('3', '3', '1'),
             (3, 3, _) => ('3', '3', 'x'),
+            (3, 4, _) => ('3', '4', 'x'),
             _ => version_error(),
         };
 
@@ -279,7 +280,7 @@ fn version_error() -> ! {
         "
 
 This crate is only compatible with OpenSSL 1.0.1 through 1.1.1, or LibreSSL 2.5
-through 3.3.x, but a different version of OpenSSL was found. The build is now aborting
+through 3.4.x, but a different version of OpenSSL was found. The build is now aborting
 due to this version mismatch.
 
 "
