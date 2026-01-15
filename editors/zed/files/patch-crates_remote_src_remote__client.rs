--- crates/remote/src/remote_client.rs.orig	2026-01-15 04:31:16 UTC
+++ crates/remote/src/remote_client.rs
@@ -54,6 +54,7 @@ pub enum RemoteOs {
     Linux,
     MacOs,
     Windows,
+    FreeBSD,
 }
 
 impl RemoteOs {
@@ -62,6 +63,7 @@ impl RemoteOs {
             RemoteOs::Linux => "linux",
             RemoteOs::MacOs => "macos",
             RemoteOs::Windows => "windows",
+            RemoteOs::FreeBSD => "freebsd",
         }
     }
 
