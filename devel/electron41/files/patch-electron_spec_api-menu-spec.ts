--- electron/spec/api-menu-spec.ts.orig	2026-05-07 20:19:20 UTC
+++ electron/spec/api-menu-spec.ts
@@ -893,7 +893,7 @@ describe('Menu module', function () {
     // https://github.com/electron/electron/issues/35724
     // Maximizing window is enough to trigger the bug
     // FIXME(dsanders11): Test always passes on CI, even pre-fix
-    ifit(process.platform === 'linux' && !process.env.CI)('does not trigger issue #35724', (done) => {
+    ifit((process.platform === 'linux' || process.platform === 'freebsd') && !process.env.CI)('does not trigger issue #35724', (done) => {
       const showAndCloseMenu = async () => {
         await setTimeout(1000);
         menu.popup({ window: w, x: 50, y: 50 });
