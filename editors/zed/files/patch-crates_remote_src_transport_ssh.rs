--- crates/remote/src/transport/ssh.rs.orig	2025-11-21 14:41:36 UTC
+++ crates/remote/src/transport/ssh.rs
@@ -1058,6 +1058,7 @@ impl SshSocket {
         let os = match os.trim() {
             "Darwin" => "macos",
             "Linux" => "linux",
+            "FreeBSD" => "freebsd",
             _ => anyhow::bail!(
                 "Prebuilt remote servers are not yet available for {os:?}. See https://zed.dev/docs/remote-development"
             ),
