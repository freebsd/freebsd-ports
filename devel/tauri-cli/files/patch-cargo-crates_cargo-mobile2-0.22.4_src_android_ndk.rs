-- Provide an Android NDK host tag for FreeBSD so cargo-mobile2 compiles on
-- FreeBSD even though the Android NDK does not officially support it.
--- cargo-crates/cargo-mobile2-0.22.4/src/android/ndk.rs.orig	2026-07-30 17:28:10 UTC
+++ cargo-crates/cargo-mobile2-0.22.4/src/android/ndk.rs
@@ -29,6 +29,11 @@ pub fn host_tag() -> &'static str {
     "linux-x86_64"
 }
 
+#[cfg(target_os = "freebsd")]
+pub fn host_tag() -> &'static str {
+    "freebsd-x86_64"
+}
+
 #[cfg(all(windows, target_pointer_width = "32"))]
 pub fn host_tag() -> &'static str {
     "windows"
