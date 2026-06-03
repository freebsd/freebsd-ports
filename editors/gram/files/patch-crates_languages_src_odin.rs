--- crates/languages/src/odin.rs.orig	2026-03-26 00:34:06 UTC
+++ crates/languages/src/odin.rs
@@ -32,6 +32,12 @@ impl OdinLspAdapter {
     const OS_NAME: &str = "unknown-linux-gnu";
 }
 
+#[cfg(target_os = "freebsd")]
+impl OdinLspAdapter {
+    const GITHUB_ASSET_KIND: AssetKind = AssetKind::Zip;
+    const OS_NAME: &str = "unknown-linux-gnu";
+}
+
 #[cfg(target_os = "windows")]
 impl OdinLspAdapter {
     const GITHUB_ASSET_KIND: AssetKind = AssetKind::Zip;
