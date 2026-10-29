--- node_modules/boxednode/lib/index.js.orig	2026-10-23 00:00:00 UTC
+++ node_modules/boxednode/lib/index.js
@@ -193,6 +193,10 @@ async function compileNode(sourcePath, linkedJSModules
         for (const module of linkedJSModules) {
             configure.push('--link-module', module);
         }
+        for (const static_lib of ['ada', 'brotli', 'cares', 'corepack', 'googletest', 'histogram', 'icu-small', 'llhttp',
+            'merve', 'nbytes', 'nghttp2', 'ngtcp2', 'npm', 'simdjson', 'sqlite', 'uv', 'uvwasi', 'zlib', 'zstd']) {
+            await fs_1.promises.rm(path_1.default.join(sourcePath, 'deps', static_lib), { recursive: true, force: true });
+        }
         await (0, helpers_1.spawnBuildCommand)(configure, options);
         if (configure.includes('--fully-static') || configure.includes('--partly-static')) {
             for (const file of [
