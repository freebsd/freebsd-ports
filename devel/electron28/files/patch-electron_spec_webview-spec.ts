--- electron/spec/webview-spec.ts.orig	2023-12-04 18:19:02 UTC
+++ electron/spec/webview-spec.ts
@@ -530,7 +530,7 @@ describe('<webview> tag', function () {
     });
 
     // FIXME(zcbenz): Fullscreen events do not work on Linux.
-    ifit(process.platform !== 'linux')('exiting fullscreen should unfullscreen window', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('exiting fullscreen should unfullscreen window', async () => {
       const [w, webview] = await loadWebViewWindow();
       const enterFullScreen = once(w, 'enter-full-screen');
       await webview.executeJavaScript('document.getElementById("div").requestFullscreen()', true);
