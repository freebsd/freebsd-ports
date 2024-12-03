--- electron/spec/chromium-spec.ts.orig	2024-11-27 04:18:00 UTC
+++ electron/spec/chromium-spec.ts
@@ -474,13 +474,13 @@ describe('command line switches', () => {
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
@@ -567,7 +567,7 @@ describe('command line switches', () => {
 
     // Disable the test on linux arm and arm64 to avoid startup crash
     // https://github.com/electron/electron/issues/44293#issuecomment-2420077154
-    ifit(process.platform !== 'linux' || (process.arch !== 'arm' && process.arch !== 'arm64'))('creates startup trace', async () => {
+    ifit((process.platform !== 'linux' && process.platform !== 'freebsd') || (process.arch !== 'arm' && process.arch !== 'arm64'))('creates startup trace', async () => {
       const rc = await startRemoteControlApp(['--trace-startup=*', `--trace-startup-file=${outputFilePath}`, '--trace-startup-duration=1', '--enable-logging']);
       const stderrComplete = new Promise<string>(resolve => {
         let stderr = '';
@@ -2917,12 +2917,12 @@ describe('font fallback', () => {
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
@@ -3318,7 +3318,7 @@ describe('navigator.clipboard.write', () => {
   });
 });
 
-ifdescribe((process.platform !== 'linux' || app.isUnityRunning()))('navigator.setAppBadge/clearAppBadge', () => {
+ifdescribe(((process.platform !== 'linux' && process.platform !== 'freebsd') || app.isUnityRunning()))('navigator.setAppBadge/clearAppBadge', () => {
   let w: BrowserWindow;
 
   const expectedBadgeCount = 42;
