--- remote/node_modules/@vscode/deviceid/dist/index.js.orig	2025-06-19 08:49:40 UTC
+++ remote/node_modules/@vscode/deviceid/dist/index.js
@@ -20,8 +20,9 @@ if (process.platform !== "win32" &&
 Object.defineProperty(exports, "__esModule", { value: true });
 if (process.platform !== "win32" &&
     process.platform !== "darwin" &&
-    process.platform !== "linux") {
+    process.platform !== "linux" &&
+    process.platform !== "freebsd") {
     throw new Error("Unsupported platform");
 }
 __exportStar(require("./devdeviceid.js"), exports);
-//# sourceMappingURL=index.js.map
\ No newline at end of file
+//# sourceMappingURL=index.js.map
