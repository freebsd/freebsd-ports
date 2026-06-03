--- node_modules/@vscode/gulp-electron/src/download.js.orig	2026-05-22 07:33:46 UTC
+++ node_modules/@vscode/gulp-electron/src/download.js
@@ -158,6 +158,7 @@ async function download(opts) {
     artifactName: opts.artifactName,
     artifactSuffix: opts.artifactSuffix,
     token: opts.token,
+    unsafelyDisableChecksums: opts.unsafelyDisableChecksums,
     downloadOptions: {
       getProgressCallback: (progress) => {
         if (bar) bar.update(progress.percent);
