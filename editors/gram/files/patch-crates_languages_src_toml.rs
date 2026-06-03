--- crates/languages/src/toml.rs.orig	2026-03-26 00:34:06 UTC
+++ crates/languages/src/toml.rs
@@ -22,6 +22,11 @@ impl TomlLspAdapter {
     const OS_NAME: &str = "linux";
 }
 
+#[cfg(target_os = "freebsd")]
+impl TomlLspAdapter {
+    const OS_NAME: &str = "linux";
+}
+
 #[cfg(target_os = "windows")]
 impl TomlLspAdapter {
     const OS_NAME: &str = "windows";
