--- cargo-crates/extism-convert-1.30.0/src/encoding.rs.orig	2026-09-18 10:03:25 UTC
+++ cargo-crates/extism-convert-1.30.0/src/encoding.rs
@@ -182,6 +182,3 @@ impl<'a, T: bytemuck::Pod> FromBytes<'a> for Raw<'a, T
         Ok(Raw(x))
     }
 }
-
-#[cfg(all(feature = "raw", target_endian = "big"))]
-compile_error!("The raw feature is only supported on little endian targets");
