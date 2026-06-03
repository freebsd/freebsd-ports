--- crates/languages/src/xml.rs.orig	2026-03-26 00:34:06 UTC
+++ crates/languages/src/xml.rs
@@ -23,6 +23,11 @@ impl XmlLspAdapter {
     const OS_NAME: &str = "linux";
 }
 
+#[cfg(target_os = "freebsd")]
+impl XmlLspAdapter {
+    const OS_NAME: &str = "linux";
+}
+
 #[cfg(target_os = "windows")]
 impl XmlLspAdapter {
     const OS_NAME: &str = "windows32";
