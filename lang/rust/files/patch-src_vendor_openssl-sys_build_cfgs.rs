--- src/vendor/openssl-sys/build/cfgs.rs.orig	2018-09-11 04:49:55 UTC
+++ src/vendor/openssl-sys/build/cfgs.rs
@@ -16,6 +16,9 @@ pub fn get(openssl_version: Option<u64>, libressl_vers
         if libressl_version >= 0x2_07_03_00_0 {
             cfgs.push("libressl273");
         }
+        if libressl_version >= 0x2_08_00_00_0 {
+            cfgs.push("libressl280");
+        }
     } else {
         let openssl_version = openssl_version.unwrap();
 
@@ -24,6 +27,9 @@ pub fn get(openssl_version: Option<u64>, libressl_vers
         }
         if openssl_version >= 0x1_00_02_00_0 {
             cfgs.push("ossl102");
+        }
+        if openssl_version >= 0x1_00_02_06_0 {
+            cfgs.push("ossl102f");
         }
         if openssl_version >= 0x1_00_02_08_0 {
             cfgs.push("ossl102h");
