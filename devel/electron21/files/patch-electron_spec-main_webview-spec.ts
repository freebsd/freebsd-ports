--- electron/spec-main/webview-spec.ts.orig	2023-01-24 08:00:52 UTC
+++ electron/spec-main/webview-spec.ts
@@ -485,7 +485,7 @@ describe('<webview> tag', function () {
     });
 
     // FIXME(zcbenz): Fullscreen events do not work on Linux.
-    ifit(process.platform !== 'linux')('exiting fullscreen should unfullscreen window', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('exiting fullscreen should unfullscreen window', async () => {
       const [w, webview] = await loadWebViewWindow();
       const enterFullScreen = emittedOnce(w, 'enter-full-screen');
       await webview.executeJavaScript('document.getElementById("div").requestFullscreen()', true);
