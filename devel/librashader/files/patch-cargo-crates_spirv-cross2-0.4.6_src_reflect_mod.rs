--- cargo-crates/spirv-cross2-0.4.6/src/reflect/mod.rs.orig	2024-12-19 08:58:24 UTC
+++ cargo-crates/spirv-cross2-0.4.6/src/reflect/mod.rs
@@ -24,7 +24,7 @@
     #[cfg(target_endian = "big")]
     let memchr = memchr::memmem::find(
         bytemuck::must_cast_slice(enum_slice),
-        &*i32::MAX.to_be_bytes(),
+        i32::MAX.to_be_bytes().as_slice(),
     );
 
     #[cfg(target_endian = "little")]
