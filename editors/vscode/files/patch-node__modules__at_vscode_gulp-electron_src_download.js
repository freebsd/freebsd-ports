--- node_modules/@vscode/gulp-electron/src/download.js.orig	2026-07-02 07:59:23 UTC
+++ node_modules/@vscode/gulp-electron/src/download.js
@@ -195,6 +195,7 @@ async function download(opts) {
     artifactName: opts.artifactName,
     artifactSuffix: opts.artifactSuffix,
     token: opts.token,
+    unsafelyDisableChecksums: opts.unsafelyDisableChecksums,
     downloadOptions: {
       getProgressCallback: (progress) => {
         if (bar) bar.update(progress.percent);
