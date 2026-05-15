--- crates/remote/src/remote_client.rs.orig	2026-05-13 17:09:47 UTC
+++ crates/remote/src/remote_client.rs
@@ -57,6 +57,7 @@ pub enum RemoteOs {
     Linux,
     MacOs,
     Windows,
+    FreeBSD,
 }
 
 impl RemoteOs {
@@ -65,6 +66,7 @@ impl RemoteOs {
             RemoteOs::Linux => "linux",
             RemoteOs::MacOs => "macos",
             RemoteOs::Windows => "windows",
+            RemoteOs::FreeBSD => "freebsd",
         }
     }
 
