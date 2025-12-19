--- crates/remote/src/transport.rs.orig	2025-12-19 13:24:55 UTC
+++ crates/remote/src/transport.rs
@@ -27,6 +27,7 @@ fn parse_platform(output: &str) -> Result<RemotePlatfo
     let os = match os {
         "Darwin" => "macos",
         "Linux" => "linux",
+        "FreeBSD" => "freebsd",
         _ => anyhow::bail!(
             "Prebuilt remote servers are not yet available for {os:?}. See https://zed.dev/docs/remote-development"
         ),
@@ -39,7 +40,9 @@ fn parse_platform(output: &str) -> Result<RemotePlatfo
         || arch.starts_with("aarch64")
     {
         "aarch64"
-    } else if arch.starts_with("x86") {
+    } else if arch.starts_with("x86")
+    	|| arch.starts_with("amd64")
+    {
         "x86_64"
     } else {
         anyhow::bail!(
