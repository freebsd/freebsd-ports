--- electron/spec/api-desktop-capturer.spec.ts.orig	2026-10-17 02:46:46 UTC
+++ electron/spec/api-desktop-capturer.spec.ts
@@ -9,7 +9,7 @@ function getSourceTypes(): ('window' | 'screen')[] {
 import { closeAllWindows } from './lib/window-helpers.ts';
 
 function getSourceTypes(): ('window' | 'screen')[] {
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     return ['screen'];
   }
   return ['window', 'screen'];
@@ -38,7 +38,7 @@ describe('desktopCapturer', { tags: ['serial'] }, () =
   });
 
   // Linux doesn't return any window sources.
-  ifit(process.platform !== 'linux')('responds to subsequent calls of different options', async () => {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('responds to subsequent calls of different options', async () => {
     const promise1 = desktopCapturer.getSources({ types: ['window'] });
     await promise1;
 
@@ -47,7 +47,7 @@ describe('desktopCapturer', { tags: ['serial'] }, () =
   });
 
   // Linux doesn't return any window sources.
-  ifit(process.platform !== 'linux')('returns an empty display_id for window sources', async () => {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('returns an empty display_id for window sources', async () => {
     const w2 = new BrowserWindow({ width: 200, height: 200 });
     await w2.loadURL('about:blank');
 
@@ -61,7 +61,7 @@ describe('desktopCapturer', { tags: ['serial'] }, () =
     }
   });
 
-  ifit(process.platform !== 'linux')('returns display_ids matching the Screen API', async () => {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('returns display_ids matching the Screen API', async () => {
     const displays = screen.getAllDisplays();
     const sources = await desktopCapturer.getSources({ types: ['screen'] });
     expect(sources).toBeInstanceOf(Array);
@@ -111,7 +111,7 @@ describe('desktopCapturer', { tags: ['serial'] }, () =
   });
 
   // Linux doesn't return any window sources.
-  ifit(process.platform !== 'linux')('getMediaSourceId should match DesktopCapturerSource.id', async () => {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('getMediaSourceId should match DesktopCapturerSource.id', async () => {
     const w2 = new BrowserWindow({ show: false, width: 100, height: 100, webPreferences: { contextIsolation: false } });
     const wShown = once(w2, 'show');
     const wFocused = once(w2, 'focus');
@@ -136,7 +136,7 @@ describe('desktopCapturer', { tags: ['serial'] }, () =
   });
 
   // Linux doesn't return any window sources.
-  ifit(process.platform !== 'linux')('getSources should not incorrectly duplicate window_id', async () => {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('getSources should not incorrectly duplicate window_id', async () => {
     const w2 = new BrowserWindow({ show: false, width: 100, height: 100, webPreferences: { contextIsolation: false } });
     const wShown = once(w2, 'show');
     const wFocused = once(w2, 'focus');
@@ -184,7 +184,7 @@ describe('desktopCapturer', { tags: ['serial'] }, () =
   });
 
   // Linux doesn't return any window sources.
-  ifit(process.platform !== 'linux')('moveAbove should move the window at the requested place', async () => {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('moveAbove should move the window at the requested place', async () => {
     // DesktopCapturer.getSources() is guaranteed to return in the correct
     // z-order from foreground to background.
     const MAX_WIN = 4;
@@ -272,7 +272,7 @@ describe('desktopCapturer', { tags: ['serial'] }, () =
 
   // Linux doesn't return any window sources.
   // Tests are sequentially dependent.
-  ifdescribe(process.platform !== 'linux')('fetchWindowIcons', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('fetchWindowIcons', () => {
     let w: BrowserWindow;
     let testSource: Electron.DesktopCapturerSource | undefined;
     let appIcon: Electron.NativeImage | undefined;
