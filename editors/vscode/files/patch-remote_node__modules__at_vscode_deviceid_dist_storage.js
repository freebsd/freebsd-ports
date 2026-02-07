--- remote/node_modules/@vscode/deviceid/dist/storage.js.orig	2025-06-19 08:49:56 UTC
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
@@ -78,4 +78,4 @@ exports.setDeviceId = setDeviceId;
     }
 }
 exports.setDeviceId = setDeviceId;
-//# sourceMappingURL=storage.js.map
\ No newline at end of file
+//# sourceMappingURL=storage.js.map
