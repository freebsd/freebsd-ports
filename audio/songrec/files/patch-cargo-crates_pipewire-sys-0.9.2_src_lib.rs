--- cargo-crates/pipewire-sys-0.9.2/src/lib.rs.orig	2026-04-19 05:10:06 UTC
+++ cargo-crates/pipewire-sys-0.9.2/src/lib.rs
@@ -11,6 +11,13 @@ pub use bindings::*;
 }
 pub use bindings::*;
 
+// On FreeBSD, pw_init and pw_deinit are macros aliasing pipewire_init/pipewire_deinit,
+// so bindgen generates the underlying symbol names. Re-export them under the expected names.
+#[cfg(target_os = "freebsd")]
+pub use bindings::pipewire_init as pw_init;
+#[cfg(target_os = "freebsd")]
+pub use bindings::pipewire_deinit as pw_deinit;
+
 #[cfg(test)]
 mod tests {
     use super::*;
