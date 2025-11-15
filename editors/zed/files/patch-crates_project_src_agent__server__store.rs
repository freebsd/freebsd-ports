--- crates/project/src/agent_server_store.rs.orig	2025-11-15 06:30:50 UTC
+++ crates/project/src/agent_server_store.rs
@@ -1343,6 +1343,8 @@ fn get_platform_info() -> Option<(&'static str, &'stat
         "pc-windows-msvc"
     } else if cfg!(target_os = "linux") {
         "unknown-linux-gnu"
+    } else if cfg!(target_os = "freebsd") {
+        "unknown-freebsd"
     } else {
         return None;
     };
@@ -1429,6 +1431,8 @@ impl ExternalAgentServer for LocalExtensionArchiveAgen
                 "linux"
             } else if cfg!(target_os = "windows") {
                 "windows"
+            } else if cfg!(target_os = "freebsd") {
+                "freebsd"
             } else {
                 anyhow::bail!("unsupported OS");
             };
