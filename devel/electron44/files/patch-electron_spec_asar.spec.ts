--- electron/spec/asar.spec.ts.orig	2026-10-15 04:11:38 UTC
+++ electron/spec/asar.spec.ts
@@ -664,7 +664,7 @@ describe('asar package', () => {
         expect(code).to.equal(0);
       });
 
-      ifit(process.platform === 'linux')(
+      ifit(process.platform === 'linux' || process.platform === 'freebsd')(
         'starts an app from an archive under a non-ASCII directory with LC_ALL=C',
         async function () {
           const app = j(tmp, unicodeDir, 'main-app.asar');
