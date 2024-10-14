--- src/system.rs.orig	2024-10-13 21:16:24 UTC
+++ src/system.rs
@@ -66,7 +66,7 @@ pub struct DefaultSystem;
 #[derive(Debug, Clone, Copy)]
 pub struct DefaultSystem;
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 impl System for DefaultSystem {
     fn set_clipboard(&mut self, s: &str) -> io::Result<()> {
         let mut child = Command::new("xclip")
