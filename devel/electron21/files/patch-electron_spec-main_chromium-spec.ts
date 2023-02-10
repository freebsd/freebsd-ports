--- electron/spec-main/chromium-spec.ts.orig	2023-01-24 08:00:52 UTC
+++ electron/spec-main/chromium-spec.ts
@@ -403,13 +403,13 @@ describe('command line switches', () => {
     it('should not set an invalid locale', async () => testLocale('asdfkl', `${currentLocale}|${currentSystemLocale}|${currentPreferredLanguages}`));
 
     const lcAll = String(process.env.LC_ALL);
-    ifit(process.platform === 'linux')('current process has a valid LC_ALL env', async () => {
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('current process has a valid LC_ALL env', async () => {
       // The LC_ALL env should not be set to DOM locale string.
       expect(lcAll).to.not.equal(app.getLocale());
     });
-    ifit(process.platform === 'linux')('should not change LC_ALL', async () => testLocale('fr', lcAll, true));
-    ifit(process.platform === 'linux')('should not change LC_ALL when setting invalid locale', async () => testLocale('asdfkl', lcAll, true));
-    ifit(process.platform === 'linux')('should not change LC_ALL when --lang is not set', async () => testLocale('', lcAll, true));
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('should not change LC_ALL', async () => testLocale('fr', lcAll, true));
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('should not change LC_ALL when setting invalid locale', async () => testLocale('asdfkl', lcAll, true));
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('should not change LC_ALL when --lang is not set', async () => testLocale('', lcAll, true));
   });
 
   describe('--remote-debugging-pipe switch', () => {
@@ -1762,7 +1762,7 @@ describe('chromium features', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'win32' && process.platform !== 'linux')('webgl', () => {
+  ifdescribe(process.platform !== 'win32' && process.platform !== 'linux' && process.platform !== 'freebsd')('webgl', () => {
     it('can be gotten as context in canvas', async () => {
       const w = new BrowserWindow({ show: false });
       w.loadURL('about:blank');
@@ -1858,12 +1858,12 @@ describe('font fallback', () => {
       expect(fonts[0].familyName).to.equal('Arial');
     } else if (process.platform === 'darwin') {
       expect(fonts[0].familyName).to.equal('Helvetica');
-    } else if (process.platform === 'linux') {
+    } else if (process.platform === 'linux' || process.platform === 'freebsd') {
       expect(fonts[0].familyName).to.equal('DejaVu Sans');
     } // I think this depends on the distro? We don't specify a default.
   });
 
-  ifit(process.platform !== 'linux')('should fall back to Japanese font for sans-serif Japanese script', async function () {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('should fall back to Japanese font for sans-serif Japanese script', async function () {
     const html = `
     <html lang="ja-JP">
       <head>
@@ -2166,7 +2166,7 @@ describe('navigator.clipboard', () => {
   });
 });
 
-ifdescribe((process.platform !== 'linux' || app.isUnityRunning()))('navigator.setAppBadge/clearAppBadge', () => {
+ifdescribe(((process.platform !== 'linux' && process.platform !== 'freebsd') || app.isUnityRunning()))('navigator.setAppBadge/clearAppBadge', () => {
   let w: BrowserWindow;
 
   const expectedBadgeCount = 42;
