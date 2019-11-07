--- vendor/openssl-sys/build/main.rs.orig	2019-11-04 17:34:46 UTC
+++ vendor/openssl-sys/build/main.rs
@@ -183,27 +183,32 @@ See rust-openssl README for more information:
     if let Some(libressl_version) = libressl_version {
         println!("cargo:libressl_version_number={:x}", libressl_version);
 
+        let major = (libressl_version >> 28) as u8;
         let minor = (libressl_version >> 20) as u8;
         let fix = (libressl_version >> 12) as u8;
-        let (minor, fix) = match (minor, fix) {
-            (5, 0) => ('5', '0'),
-            (5, 1) => ('5', '1'),
-            (5, 2) => ('5', '2'),
-            (5, _) => ('5', 'x'),
-            (6, 0) => ('6', '0'),
-            (6, 1) => ('6', '1'),
-            (6, 2) => ('6', '2'),
-            (6, _) => ('6', 'x'),
-            (7, _) => ('7', 'x'),
-            (8, 0) => ('8', '0'),
-            (8, 1) => ('8', '1'),
-            (8, _) => ('8', 'x'),
-            (9, 0) => ('9', '0'),
+        let (major, minor, fix) = match (major, minor, fix) {
+            (2, 5, 0) => ('2', '5', '0'),
+            (2, 5, 1) => ('2', '5', '1'),
+            (2, 5, 2) => ('2', '5', '2'),
+            (2, 5, _) => ('2', '5', 'x'),
+            (2, 6, 0) => ('2', '6', '0'),
+            (2, 6, 1) => ('2', '6', '1'),
+            (2, 6, 2) => ('2', '6', '2'),
+            (2, 6, _) => ('2', '6', 'x'),
+            (2, 7, _) => ('2', '7', 'x'),
+            (2, 8, 0) => ('2', '8', '0'),
+            (2, 8, 1) => ('2', '8', '1'),
+            (2, 8, _) => ('2', '8', 'x'),
+            (2, 9, 0) => ('2', '9', '0'),
+            (2, 9, _) => ('2', '9', 'x'),
+            (3, 0, 0) => ('3', '0', '0'),
+            (3, 0, 1) => ('3', '0', '1'),
+            (3, 0, _) => ('3', '0', 'x'),
             _ => version_error(),
         };
 
         println!("cargo:libressl=true");
-        println!("cargo:libressl_version=2{}{}", minor, fix);
+        println!("cargo:libressl_version={}{}{}", major, minor, fix);
         println!("cargo:version=101");
         Version::Libressl
     } else {
@@ -239,7 +244,7 @@ fn version_error() -> ! {
         "
 
 This crate is only compatible with OpenSSL 1.0.1 through 1.1.1, or LibreSSL 2.5
-through 2.9.0, but a different version of OpenSSL was found. The build is now aborting
+through 3.0.x, but a different version of OpenSSL was found. The build is now aborting
 due to this version mismatch.
 
 "
