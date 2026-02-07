--- crates/remote/src/remote_client.rs.orig	2026-01-29 22:37:26 UTC
+++ crates/remote/src/remote_client.rs
@@ -56,6 +56,7 @@ pub enum RemoteOs {
     Linux,
     MacOs,
     Windows,
+    FreeBSD,
 }
 
 impl RemoteOs {
@@ -64,6 +65,7 @@ impl RemoteOs {
             RemoteOs::Linux => "linux",
             RemoteOs::MacOs => "macos",
             RemoteOs::Windows => "windows",
+            RemoteOs::FreeBSD => "freebsd",
         }
     }
 
