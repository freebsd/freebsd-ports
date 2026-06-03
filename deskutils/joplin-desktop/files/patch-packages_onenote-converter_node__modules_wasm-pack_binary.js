--- packages/onenote-converter/node_modules/wasm-pack/binary.js.orig	2025-09-03 06:07:11 UTC
+++ packages/onenote-converter/node_modules/wasm-pack/binary.js
@@ -18,6 +18,10 @@ const getPlatform = () => {
   if (type === "Linux" && arch === "arm64") {
     return "aarch64-unknown-linux-musl";
   }
+  // dummy just to avoid unsupported platform error
+  if (type === "FreeBSD" && arch === "x64") {
+    return "x86_64-unknown-linux-musl";
+  }
   if (type === "Darwin" && (arch === "x64" || arch === "arm64")) {
     return "x86_64-apple-darwin";
   }
