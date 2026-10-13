--- cargo-crates/openssl-sys-0.9.117/build/cfgs.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/openssl-sys-0.9.117/build/cfgs.rs
@@ -50,6 +50,9 @@ pub fn get(openssl_version: Option<u64>, libressl_vers
         if libressl_version >= 0x4_03_00_00_0 {
             cfgs.push("libressl430");
         }
+        if libressl_version >= 0x4_04_00_00_0 {
+            cfgs.push("libressl440");
+        }
     } else {
         let openssl_version = openssl_version.unwrap();
         cfgs.push("ossl101");
