--- vendor/openssl-sys/build/main.rs.ORIG	2020-10-07 02:33:31.000000000 -0700
+++ vendor/openssl-sys/build/main.rs	2020-10-23 20:45:37.047602000 -0700
@@ -221,6 +221,7 @@
             (3, 1, 0) => ('3', '1', '0'),
             (3, 1, _) => ('3', '1', 'x'),
             (3, 2, 0) => ('3', '2', '0'),
+            (3, 2, 2) => ('3', '2', '2'),
             _ => version_error(),
         };
 
@@ -261,7 +262,7 @@
         "
 
 This crate is only compatible with OpenSSL 1.0.1 through 1.1.1, or LibreSSL 2.5
-through 3.2.0, but a different version of OpenSSL was found. The build is now aborting
+through 3.2.2, but a different version of OpenSSL was found. The build is now aborting
 due to this version mismatch.
 
 "
