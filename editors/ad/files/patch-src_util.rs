--- src/util.rs.orig	2024-10-04 13:50:39 UTC
+++ src/util.rs
@@ -12,7 +12,7 @@ use std::{
     thread::spawn,
 };
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 /// Set the current system clipboard state using xclip.
 pub fn set_clipboard(s: &str) -> io::Result<()> {
     let mut child = Command::new("xclip")
@@ -23,7 +23,7 @@ pub fn set_clipboard(s: &str) -> io::Result<()> {
     child.stdin.take().unwrap().write_all(s.as_bytes())
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 /// Read the current system clipboard state using xclip.
 pub fn read_clipboard() -> io::Result<String> {
     let output = Command::new("xclip")
