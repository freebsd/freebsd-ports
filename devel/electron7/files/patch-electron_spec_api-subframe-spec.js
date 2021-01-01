--- electron/spec/api-subframe-spec.js.orig	2020-03-24 05:00:48 UTC
+++ electron/spec/api-subframe-spec.js
@@ -188,7 +188,7 @@ describe('cross-site frame sandboxing', () => {
   let server = null;
 
   beforeEach(function () {
-    if (process.platform === 'linux') {
+    if (process.platform === 'linux' || process.platform === 'freebsd') {
       this.skip();
     }
   });
