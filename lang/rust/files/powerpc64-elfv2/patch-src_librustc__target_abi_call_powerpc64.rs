--- src/librustc_target/abi/call/powerpc64.rs.orig	2020-03-09 22:11:17 UTC
+++ src/librustc_target/abi/call/powerpc64.rs
@@ -123,7 +123,7 @@ where
         ELFv2
     } else {
         match cx.data_layout().endian {
-            Endian::Big => ELFv1,
+            Endian::Big => ELFv2,
             Endian::Little => ELFv2,
         }
     };
