--- electron/spec/api-menu.spec.ts.orig	2026-11-18 23:46:22 UTC
+++ electron/spec/api-menu.spec.ts
@@ -1008,7 +1008,7 @@ describe('Menu module', () => {
     // https://github.com/electron/electron/issues/35724
     // Maximizing window is enough to trigger the bug
     // FIXME(dsanders11): Test always passes on CI, even pre-fix
-    ifit(process.platform === 'linux' && !process.env.CI)(
+    ifit((process.platform === 'linux' || process.platform === 'freebsd') && !process.env.CI)(
       'does not trigger issue #35724',
       () =>
         new Promise<void>((resolve, reject) => {
