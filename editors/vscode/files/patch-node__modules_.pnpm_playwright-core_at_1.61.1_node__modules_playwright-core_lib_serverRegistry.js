--- node_modules/.pnpm/playwright-core@1.61.1/node_modules/playwright-core/lib/serverRegistry.js.orig	1971-12-10 00:00:00 UTC
+++ node_modules/.pnpm/playwright-core@1.61.1/node_modules/playwright-core/lib/serverRegistry.js
@@ -7277,7 +7277,7 @@ var defaultCacheDirectory = (() => {
   });
 }
 var defaultCacheDirectory = (() => {
-  if (process.platform === "linux")
+  if (process.platform === "linux" || process.platform === "freebsd")
     return process.env.XDG_CACHE_HOME || import_path2.default.join(import_os.default.homedir(), ".cache");
   if (process.platform === "darwin")
     return import_path2.default.join(import_os.default.homedir(), "Library", "Caches");
