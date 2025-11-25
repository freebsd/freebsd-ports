--- crates/remote/src/transport/ssh.rs.orig	2025-11-24 20:23:08 UTC
+++ crates/remote/src/transport/ssh.rs
@@ -1058,6 +1058,7 @@ impl SshSocket {
         let os = match os.trim() {
             "Darwin" => "macos",
             "Linux" => "linux",
+            "FreeBSD" => "freebsd",
             _ => anyhow::bail!(
                 "Prebuilt remote servers are not yet available for {os:?}. See https://zed.dev/docs/remote-development"
             ),
@@ -1069,7 +1070,9 @@ impl SshSocket {
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
