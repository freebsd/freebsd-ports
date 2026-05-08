--- crates/extension_host/src/wasm_host/wit/since_v0_8_0.rs.orig	2026-05-06 20:35:33 UTC
+++ crates/extension_host/src/wasm_host/wit/since_v0_8_0.rs
@@ -846,7 +846,7 @@ impl platform::Host for WasmState {
         Ok((
             match env::consts::OS {
                 "macos" => platform::Os::Mac,
-                "linux" => platform::Os::Linux,
+                "linux" | "freebsd" => platform::Os::Linux,
                 "windows" => platform::Os::Windows,
                 _ => panic!("unsupported os"),
             },
