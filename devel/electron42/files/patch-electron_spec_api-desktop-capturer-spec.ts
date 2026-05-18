--- electron/spec/api-desktop-capturer-spec.ts.orig	2026-05-07 20:19:20 UTC
+++ electron/spec/api-desktop-capturer-spec.ts
@@ -9,7 +9,7 @@ function getSourceTypes(): ('window' | 'screen')[] {
 import { closeAllWindows } from './lib/window-helpers';
 
 function getSourceTypes(): ('window' | 'screen')[] {
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     return ['screen'];
   }
   return ['window', 'screen'];
@@ -35,7 +35,7 @@ describe('desktopCapturer', () => {
   });
 
   // Linux doesn't return any window sources.
-  ifit(process.platform !== 'linux')('responds to subsequent calls of different options', async () => {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('responds to subsequent calls of different options', async () => {
     const promise1 = desktopCapturer.getSources({ types: ['window'] });
     await expect(promise1).to.eventually.be.fulfilled();
 
@@ -44,7 +44,7 @@ describe('desktopCapturer', () => {
   });
 
   // Linux doesn't return any window sources.
-  ifit(process.platform !== 'linux')('returns an empty display_id for window sources', async () => {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('returns an empty display_id for window sources', async () => {
     const w2 = new BrowserWindow({ width: 200, height: 200 });
     await w2.loadURL('about:blank');
 
@@ -56,7 +56,7 @@ describe('desktopCapturer', () => {
     }
   });
 
-  ifit(process.platform !== 'linux')('returns display_ids matching the Screen API', async () => {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('returns display_ids matching the Screen API', async () => {
     const displays = screen.getAllDisplays();
     const sources = await desktopCapturer.getSources({ types: ['screen'] });
     expect(sources).to.be.an('array').of.length(displays.length);
@@ -103,7 +103,7 @@ describe('desktopCapturer', () => {
   });
 
   // Linux doesn't return any window sources.
-  ifit(process.platform !== 'linux')('getMediaSourceId should match DesktopCapturerSource.id', async function () {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('getMediaSourceId should match DesktopCapturerSource.id', async function () {
     const w2 = new BrowserWindow({ show: false, width: 100, height: 100, webPreferences: { contextIsolation: false } });
     const wShown = once(w2, 'show');
     const wFocused = once(w2, 'focus');
@@ -127,7 +127,7 @@ describe('desktopCapturer', () => {
   });
 
   // Linux doesn't return any window sources.
-  ifit(process.platform !== 'linux')('getSources should not incorrectly duplicate window_id', async function () {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('getSources should not incorrectly duplicate window_id', async function () {
     const w2 = new BrowserWindow({ show: false, width: 100, height: 100, webPreferences: { contextIsolation: false } });
     const wShown = once(w2, 'show');
     const wFocused = once(w2, 'focus');
@@ -173,7 +173,7 @@ describe('desktopCapturer', () => {
   });
 
   // Linux doesn't return any window sources.
-  ifit(process.platform !== 'linux')('moveAbove should move the window at the requested place', async function () {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('moveAbove should move the window at the requested place', async function () {
     // DesktopCapturer.getSources() is guaranteed to return in the correct
     // z-order from foreground to background.
     const MAX_WIN = 4;
@@ -259,7 +259,7 @@ describe('desktopCapturer', () => {
   });
 
   // Linux doesn't return any window sources.
-  ifdescribe(process.platform !== 'linux')('fetchWindowIcons', function () {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('fetchWindowIcons', function () {
     // Tests are sequentially dependent
     this.bail(true);
     let w: BrowserWindow;
