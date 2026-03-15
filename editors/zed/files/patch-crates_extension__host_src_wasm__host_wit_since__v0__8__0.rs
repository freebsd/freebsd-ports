--- crates/extension_host/src/wasm_host/wit/since_v0_8_0.rs.orig	2026-03-12 22:50:21.117154000 -0600
+++ crates/extension_host/src/wasm_host/wit/since_v0_8_0.rs	2026-03-12 22:44:47.087476000 -0600
@@ -835,7 +835,7 @@
         Ok((
             match env::consts::OS {
                 "macos" => platform::Os::Mac,
-                "linux" => platform::Os::Linux,
+                "linux" | "freebsd" => platform::Os::Linux,
                 "windows" => platform::Os::Windows,
                 _ => panic!("unsupported os"),
             },
