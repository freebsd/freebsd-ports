--- electron/spec/api-menu-spec.ts.orig	2023-04-18 08:44:40 UTC
+++ electron/spec/api-menu-spec.ts
@@ -890,7 +890,7 @@ describe('Menu module', function () {
     // https://github.com/electron/electron/issues/35724
     // Maximizing window is enough to trigger the bug
     // FIXME(dsanders11): Test always passes on CI, even pre-fix
-    ifit(process.platform === 'linux' && !process.env.CI)('does not trigger issue #35724', (done) => {
+    ifit((process.platform === 'linux' || process.platform === 'freebsd') && !process.env.CI)('does not trigger issue #35724', (done) => {
       const showAndCloseMenu = async () => {
         await delay(1000);
         menu.popup({ window: w, x: 50, y: 50 });
