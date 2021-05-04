--- vendor/openssl-sys/build/main.rs.orig	2020-11-16 06:27:50.000000000 -0800
+++ vendor/openssl-sys/build/main.rs	2020-12-11 12:47:11.685331000 -0800
@@ -221,6 +221,8 @@
             (3, 1, 0) => ('3', '1', '0'),
             (3, 1, _) => ('3', '1', 'x'),
             (3, 2, 0) => ('3', '2', '0'),
+            (3, 2, _) => ('3', '2', 'x'),
+            (3, 3, _) => ('3', '3', 'x'),
             _ => version_error(),
         };
 
@@ -261,7 +263,7 @@
         "
 
 This crate is only compatible with OpenSSL 1.0.1 through 1.1.1, or LibreSSL 2.5
-through 3.2.0, but a different version of OpenSSL was found. The build is now aborting
+through 3.3.x, but a different version of OpenSSL was found. The build is now aborting
 due to this version mismatch.
 
 "
