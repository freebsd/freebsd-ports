--- electron/spec/webview-spec.ts.orig	2024-07-15 16:16:34 UTC
+++ electron/spec/webview-spec.ts
@@ -555,7 +555,7 @@ describe('<webview> tag', function () {
     });
 
     // FIXME(zcbenz): Fullscreen events do not work on Linux.
-    ifit(process.platform !== 'linux')('exiting fullscreen should unfullscreen window', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('exiting fullscreen should unfullscreen window', async () => {
       const [w, webview] = await loadWebViewWindow();
       const enterFullScreen = once(w, 'enter-full-screen');
       await webview.executeJavaScript('document.getElementById("div").requestFullscreen()', true);
@@ -1989,7 +1989,7 @@ describe('<webview> tag', function () {
 
     ifdescribe(features.isPrintingEnabled())('<webview>.printToPDF()', () => {
       // FIXME: This test is flaky on Linux x64 only in 29-x-y, skip it there.
-      ifit(process.platform !== 'linux' && process.arch !== 'x64')('rejects on incorrectly typed parameters', async () => {
+      ifit((process.platform !== 'linux' && process.platform !== 'freebsd') && process.arch !== 'x64')('rejects on incorrectly typed parameters', async () => {
         const badTypes = {
           landscape: [],
           displayHeaderFooter: '123',
