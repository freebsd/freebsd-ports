--- node_modules/playwright/node_modules/playwright-core/lib/server/registry/index.js.orig	2026-03-25 11:59:27 UTC
+++ node_modules/playwright/node_modules/playwright-core/lib/server/registry/index.js
@@ -431,7 +431,7 @@ const registryDirectory = (() => {
     result = envDefined;
   } else {
     let cacheDirectory;
-    if (process.platform === "linux")
+    if (process.platform === "linux" || process.platform === "freebsd")
       cacheDirectory = process.env.XDG_CACHE_HOME || import_path.default.join(import_os.default.homedir(), ".cache");
     else if (process.platform === "darwin")
       cacheDirectory = import_path.default.join(import_os.default.homedir(), "Library", "Caches");
