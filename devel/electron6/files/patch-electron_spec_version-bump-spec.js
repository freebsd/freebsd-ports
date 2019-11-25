--- electron/spec/version-bump-spec.js.orig	2019-09-11 17:30:11 UTC
+++ electron/spec/version-bump-spec.js
@@ -51,7 +51,7 @@ describeFn('bump-version script', () => {
   const betaPattern = /[0-9.]*(-beta[0-9.]*)/g
 
   before(function () {
-    if (process.platform === 'linux' && process.arch === 'arm') {
+    if ((process.platform === 'linux' || process.platform === 'freebsd') && process.arch === 'arm') {
       this.skip()
     }
   })
