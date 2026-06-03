--- remote/node_modules/@vscode/deviceid/dist/storage.js.orig	2026-02-09 08:29:53 UTC
+++ remote/node_modules/@vscode/deviceid/dist/storage.js
@@ -42,7 +42,7 @@ function getDirectory() {
     if (process.platform === "darwin") {
         folder = path.join(process.env.HOME, "Library", "Application Support");
     }
-    else if (process.platform === "linux") {
+    else if (process.platform === "linux" || process.platform === "freebsd") {
         folder =
             process.env.XDG_CACHE_HOME ?? path.join(process.env.HOME, ".cache");
     }
@@ -87,4 +87,4 @@ exports.setDeviceId = setDeviceId;
     }
 }
 exports.setDeviceId = setDeviceId;
-//# sourceMappingURL=storage.js.map
\ No newline at end of file
+//# sourceMappingURL=storage.js.map
