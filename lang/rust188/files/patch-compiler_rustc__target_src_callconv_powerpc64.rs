--- compiler/rustc_target/src/callconv/powerpc64.rs.orig	2020-03-09 22:11:17 UTC
+++ compiler/rustc_target/src/callconv/powerpc64.rs
@@ -95,7 +95,7 @@ where
         ELFv2
     } else {
         match cx.data_layout().endian {
-            Endian::Big => ELFv1,
+            Endian::Big => ELFv2,
             Endian::Little => ELFv2,
         }
     };
