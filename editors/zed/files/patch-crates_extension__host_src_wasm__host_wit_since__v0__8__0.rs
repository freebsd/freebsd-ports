--- crates/extension_host/src/wasm_host/wit/since_v0_8_0.rs.orig	2026-09-04 14:25:12 UTC
+++ crates/extension_host/src/wasm_host/wit/since_v0_8_0.rs
@@ -874,7 +874,7 @@ impl platform::Host for WasmState {
         Ok((
             match env::consts::OS {
                 "macos" => platform::Os::Mac,
-                "linux" => platform::Os::Linux,
+                "linux" | "freebsd" => platform::Os::Linux,
                 "windows" => platform::Os::Windows,
                 _ => return Err(wasmtime::Error::msg("unsupported os")),
             },
