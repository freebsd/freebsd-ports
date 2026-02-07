--- cargo-crates/openssl-sys-0.9.61/build/cfgs.rs.orig2021-01-01 00:00:00 UTC
+++ cargo-crates/openssl-sys-0.9.61/build/cfgs.rs
@@ -67,6 +67,9 @@
         if openssl_version >= 0x1_01_01_03_0 {
             cfgs.push("ossl111c");
         }
+        if openssl_version >= 0x3_00_00_00_0 {
+            cfgs.push("ossl300");
+        }
     }
 
     cfgs
