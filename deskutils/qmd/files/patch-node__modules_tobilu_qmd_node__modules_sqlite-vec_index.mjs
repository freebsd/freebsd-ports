--- node_modules/@tobilu/qmd/node_modules/sqlite-vec/index.mjs.orig	2026-05-03 09:07:15 UTC
+++ node_modules/@tobilu/qmd/node_modules/sqlite-vec/index.mjs
@@ -15,9 +15,7 @@ function validPlatform(platform, arch) {
 const extensionNotFoundErrorMessage = packageName => `Loadble extension for ${BASE_PACKAGE_NAME} not found. Was the ${packageName} package installed?`;
 
 function validPlatform(platform, arch) {
-  return (
-    supportedPlatforms.find(([p, a]) => platform === p && arch === a) !== undefined
-  );
+  return true;
 }
 function extensionSuffix(platform) {
   if (platform === "win32") return "dll";
@@ -29,14 +27,7 @@ function getLoadablePath() {
 }
 
 function getLoadablePath() {
-  if (!validPlatform(platform, arch)) {
-    throw new Error(
-      invalidPlatformErrorMessage
-    );
-  }
-  const packageName = platformPackageName(platform, arch);
-  const loadablePath = fileURLToPath(import.meta.resolve(packageName + "/" + ENTRYPOINT_BASE_NAME + "." + extensionSuffix(platform)));
-  return loadablePath;
+  return fileURLToPath(new URL("vec0.so", import.meta.url));
 }
 
 function load(db) {
