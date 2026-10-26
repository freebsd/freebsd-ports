--- crates/remote/src/remote_client.rs.orig	2026-10-23 12:50:45 UTC
+++ crates/remote/src/remote_client.rs
@@ -58,6 +58,7 @@ pub enum RemoteOs {
     Linux,
     MacOs,
     Windows,
+    FreeBSD,
 }
 
 impl RemoteOs {
@@ -66,6 +67,7 @@ impl RemoteOs {
             RemoteOs::Linux => "linux",
             RemoteOs::MacOs => "macos",
             RemoteOs::Windows => "windows",
+            RemoteOs::FreeBSD => "freebsd",
         }
     }
 
@@ -80,6 +82,7 @@ impl RemoteOs {
             RemoteOs::Linux => "Linux",
             RemoteOs::MacOs => "macOS",
             RemoteOs::Windows => "Windows",
+            RemoteOs::FreeBSD => "FreeBSD",
         }
     }
 }
