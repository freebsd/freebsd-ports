--- crates/languages/src/html.rs.orig	2026-03-26 00:34:06 UTC
+++ crates/languages/src/html.rs
@@ -31,6 +31,12 @@ impl SuperhtmlLspAdapter {
     const OS_NAME: &str = "linux-musl";
 }
 
+#[cfg(target_os = "freebsd")]
+impl SuperhtmlLspAdapter {
+    const GITHUB_ASSET_KIND: AssetKind = AssetKind::TarGz;
+    const OS_NAME: &str = "linux-musl";
+}
+
 #[cfg(target_os = "windows")]
 impl SuperhtmlLspAdapter {
     const GITHUB_ASSET_KIND: AssetKind = AssetKind::Zip;
