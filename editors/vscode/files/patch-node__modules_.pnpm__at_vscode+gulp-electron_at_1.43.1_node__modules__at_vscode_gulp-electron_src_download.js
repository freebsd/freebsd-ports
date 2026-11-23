--- node_modules/.pnpm/@vscode+gulp-electron@1.43.1/node_modules/@vscode/gulp-electron/src/download.js.orig	1971-12-10 00:00:00 UTC
+++ node_modules/.pnpm/@vscode+gulp-electron@1.43.1/node_modules/@vscode/gulp-electron/src/download.js
@@ -195,6 +195,7 @@ async function download(opts) {
     artifactName: opts.artifactName,
     artifactSuffix: opts.artifactSuffix,
     token: opts.token,
+    unsafelyDisableChecksums: opts.unsafelyDisableChecksums,
     downloadOptions: {
       getProgressCallback: (progress) => {
         if (bar) bar.update(progress.percent);
