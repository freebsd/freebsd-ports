--- crates/remote/src/transport/ssh.rs.orig	2025-12-03 16:43:47 UTC
+++ crates/remote/src/transport/ssh.rs
@@ -1059,6 +1059,7 @@ impl SshSocket {
         let os = match os.trim() {
             "Darwin" => "macos",
             "Linux" => "linux",
+            "FreeBSD" => "freebsd",
             _ => anyhow::bail!(
                 "Prebuilt remote servers are not yet available for {os:?}. See https://zed.dev/docs/remote-development"
             ),
@@ -1070,7 +1071,9 @@ impl SshSocket {
             || arch.starts_with("aarch64")
         {
             "aarch64"
-        } else if arch.starts_with("x86") {
+        } else if arch.starts_with("x86")
+            || arch.starts_with("amd64")
+        {
             "x86_64"
         } else {
             anyhow::bail!(
