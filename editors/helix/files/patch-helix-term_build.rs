--- helix-term/build.rs.orig	2022-03-30 19:59:17 UTC
+++ helix-term/build.rs
@@ -5,12 +5,7 @@ use std::process::Command;
 const VERSION: &str = include_str!("../VERSION");
 
 fn main() {
-    let git_hash = Command::new("git")
-        .args(&["rev-parse", "HEAD"])
-        .output()
-        .ok()
-        .filter(|output| output.status.success())
-        .and_then(|x| String::from_utf8(x.stdout).ok());
+    let git_hash: Option<&String> = None;
 
     let version: Cow<_> = match git_hash {
         Some(git_hash) => format!("{} ({})", VERSION, &git_hash[..8]).into(),
