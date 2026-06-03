--- crates/languages/src/opentofu.rs.orig	2026-03-26 00:34:06 UTC
+++ crates/languages/src/opentofu.rs
@@ -22,6 +22,11 @@ impl OpenTofuLspAdapter {
     const OS_NAME: &str = "Linux";
 }
 
+#[cfg(target_os = "freebsd")]
+impl OpenTofuLspAdapter {
+    const OS_NAME: &str = "Linux";
+}
+
 #[cfg(target_os = "windows")]
 impl OpenTofuLspAdapter {
     const OS_NAME: &str = "Windows";
