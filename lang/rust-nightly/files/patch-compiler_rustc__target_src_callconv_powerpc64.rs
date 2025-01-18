--- compiler/rustc_target/src/callconv/powerpc64.rs.orig	2024-12-10 13:16:09 UTC
+++ compiler/rustc_target/src/callconv/powerpc64.rs
@@ -105,7 +105,7 @@ where
         AIX
     } else {
         match cx.data_layout().endian {
-            Endian::Big => ELFv1,
+            Endian::Big => ELFv2,
             Endian::Little => ELFv2,
         }
     };
