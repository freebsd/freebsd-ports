--- electron/spec-main/api-browser-view-spec.ts.orig	2022-08-03 02:37:19 UTC
+++ electron/spec-main/api-browser-view-spec.ts
@@ -63,7 +63,7 @@ describe('BrowserView module', () => {
     });
 
     // Linux and arm64 platforms (WOA and macOS) do not return any capture sources
-    ifit(process.platform !== 'linux' && process.arch !== 'arm64')('sets the background color to transparent if none is set', async () => {
+    ifit((process.platform !== 'linux' && process.platform !== 'freebsd') && process.arch !== 'arm64')('sets the background color to transparent if none is set', async () => {
       const display = screen.getPrimaryDisplay();
       const WINDOW_BACKGROUND_COLOR = '#55ccbb';
 
@@ -87,7 +87,7 @@ describe('BrowserView module', () => {
     });
 
     // Linux and arm64 platforms (WOA and macOS) do not return any capture sources
-    ifit(process.platform !== 'linux' && process.arch !== 'arm64')('successfully applies the background color', async () => {
+    ifit((process.platform !== 'linux' && process.platform !== 'freebsd') && process.arch !== 'arm64')('successfully applies the background color', async () => {
       const WINDOW_BACKGROUND_COLOR = '#55ccbb';
       const VIEW_BACKGROUND_COLOR = '#ff00ff';
       const display = screen.getPrimaryDisplay();
