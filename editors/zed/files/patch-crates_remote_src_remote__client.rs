--- crates/remote/src/remote_client.rs.orig	2026-07-01 15:07:44 UTC
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
 
@@ -79,6 +81,7 @@ impl RemoteOs {
             RemoteOs::Linux => "Linux",
             RemoteOs::MacOs => "macOS",
             RemoteOs::Windows => "Windows",
+            RemoteOs::FreeBSD => "FreeBSD",
         }
     }
 }
