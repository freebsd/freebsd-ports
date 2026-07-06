--- cargo-crates/pipewire-sys-0.10.0/src/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/pipewire-sys-0.10.0/src/lib.rs
@@ -12,6 +12,13 @@ pub use bindings::*;
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
