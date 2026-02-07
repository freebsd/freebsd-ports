--- src/os_commands.rs.orig	2021-06-02 07:37:39 UTC
+++ src/os_commands.rs
@@ -3,6 +3,11 @@ pub fn open_command(path: &str) -> String {
   format!("xdg-open \"{}\"", path)
 }
 
+#[cfg(target_os = "freebsd")]
+pub fn open_command(path: &str) -> String {
+  format!("xdg-open \"{}\"", path)
+}
+
 #[cfg(target_os = "macos")]
 pub fn open_command(path: &str) -> String {
   format!("open \"{}\"", path)
