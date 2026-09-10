--- packages/app-desktop/node_modules/sqlite-vec/index.cjs.orig	2026-09-07 14:04:41 UTC
+++ packages/app-desktop/node_modules/sqlite-vec/index.cjs
@@ -5,7 +5,7 @@ const ENTRYPOINT_BASE_NAME = "vec0";
 
 const BASE_PACKAGE_NAME = "sqlite-vec";
 const ENTRYPOINT_BASE_NAME = "vec0";
-const supportedPlatforms = [["darwin","x64"],["linux","x64"],["darwin","arm64"],["win32","x64"],["linux","arm64"]];
+const supportedPlatforms = [["darwin","x64"],["linux","x64"],["darwin","arm64"],["win32","x64"],["linux","arm64"],["freebsd","x64"]];
 
 const invalidPlatformErrorMessage = `Unsupported platform for ${BASE_PACKAGE_NAME}, on a ${platform}-${arch} machine. Supported platforms are (${supportedPlatforms
   .map(([p, a]) => `${p}-${a}`)
