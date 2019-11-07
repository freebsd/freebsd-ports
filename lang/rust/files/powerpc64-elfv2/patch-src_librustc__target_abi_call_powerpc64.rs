--- src/librustc_target/abi/call/powerpc64.rs.orig	2019-09-23 21:15:52 UTC
+++ src/librustc_target/abi/call/powerpc64.rs
@@ -128,7 +128,7 @@ pub fn compute_abi_info<'a, Ty, C>(cx: &C, fty: &mut F
         ELFv2
     } else {
         match cx.data_layout().endian {
-            Endian::Big => ELFv1,
+            Endian::Big => ELFv2,
             Endian::Little => ELFv2
         }
     };
