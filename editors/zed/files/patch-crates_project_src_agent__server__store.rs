--- crates/project/src/agent_server_store.rs.orig	2025-12-11 21:24:05 UTC
+++ crates/project/src/agent_server_store.rs
@@ -1519,6 +1519,8 @@ fn get_platform_info() -> Option<(&'static str, &'stat
         "pc-windows-msvc"
     } else if cfg!(target_os = "linux") {
         "unknown-linux-gnu"
+    } else if cfg!(target_os = "freebsd") {
+        "unknown-freebsd"
     } else {
         return None;
     };
@@ -1605,6 +1607,8 @@ impl ExternalAgentServer for LocalExtensionArchiveAgen
                 "linux"
             } else if cfg!(target_os = "windows") {
                 "windows"
+            } else if cfg!(target_os = "freebsd") {
+                "freebsd"
             } else {
                 anyhow::bail!("unsupported OS");
             };
