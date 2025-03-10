--- compiler/rustc_target/src/spec/base/freebsd.rs.orig	2024-11-16 UTC
+++ compiler/rustc_target/src/spec/base/freebsd.rs
@@ -9,7 +9,7 @@ pub fn opts() -> TargetOptions {
         crt_static_respected: true,
         position_independent_executables: true,
         relro_level: RelroLevel::Full,
-        has_thread_local: true,
+        has_thread_local: false,
         abi_return_struct_as_int: true,
         default_dwarf_version: 2,
         ..Default::default()
