--- node_modules/@vscode/gulp-electron/src/download.js.orig	2025-07-12 11:54:58 UTC
+++ node_modules/@vscode/gulp-electron/src/download.js
@@ -103,6 +103,7 @@ async function download(opts) {
     artifactName: opts.artifactName,
     artifactSuffix: opts.artifactSuffix,
     token: opts.token,
+    unsafelyDisableChecksums: opts.unsafelyDisableChecksums,
     downloadOptions: {
       getProgressCallback: (progress) => {
         if (bar) bar.update(progress.percent);
