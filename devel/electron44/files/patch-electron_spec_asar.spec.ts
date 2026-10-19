--- electron/spec/asar.spec.ts.orig	2026-10-17 02:46:46 UTC
+++ electron/spec/asar.spec.ts
@@ -662,7 +662,7 @@ describe('asar package', () => {
         expect(code).toBe(0);
       });
 
-      ifit(process.platform === 'linux')(
+      ifit(process.platform === 'linux' || process.platform === 'freebsd')(
         'starts an app from an archive under a non-ASCII directory with LC_ALL=C',
         async () => {
           const app = j(tmp, unicodeDir, 'main-app.asar');
