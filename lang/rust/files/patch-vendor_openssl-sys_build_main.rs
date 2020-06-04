--- vendor/openssl-sys/build/main.rs.orig	2020-06-01 17:45:25 UTC
+++ vendor/openssl-sys/build/main.rs
@@ -204,6 +204,9 @@ See rust-openssl README for more information:
             (3, 0, 0) => ('3', '0', '0'),
             (3, 0, 1) => ('3', '0', '1'),
             (3, 0, _) => ('3', '0', 'x'),
+            (3, 1, 0) => ('3', '1', '0'),
+            (3, 1, _) => ('3', '1', 'x'),
+            (3, 2, 0) => ('3', '2', '0'),
             _ => version_error(),
         };
 
@@ -244,7 +247,7 @@ fn version_error() -> ! {
         "
 
 This crate is only compatible with OpenSSL 1.0.1 through 1.1.1, or LibreSSL 2.5
-through 3.0.x, but a different version of OpenSSL was found. The build is now aborting
+through 3.2.0, but a different version of OpenSSL was found. The build is now aborting
 due to this version mismatch.
 
 "
