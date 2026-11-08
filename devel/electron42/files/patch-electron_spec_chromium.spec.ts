--- electron/spec/chromium.spec.ts.orig	2026-10-15 23:46:52 UTC
+++ electron/spec/chromium.spec.ts
@@ -611,15 +611,15 @@ describe('command line switches', () => {
       testLocale('asdfkl', `${currentLocale}|${currentSystemLocale}|${currentPreferredLanguages}`));
 
     const lcAll = String(process.env.LC_ALL);
-    ifit(process.platform === 'linux')('current process has a valid LC_ALL env', async () => {
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('current process has a valid LC_ALL env', async () => {
       // The LC_ALL env should not be set to DOM locale string.
       expect(lcAll).not.toBe(app.getLocale());
     });
-    ifit(process.platform === 'linux')('should not change LC_ALL', async () => testLocale('fr', lcAll, true));
-    ifit(process.platform === 'linux')('should not change LC_ALL when setting invalid locale', async () =>
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('should not change LC_ALL', async () => testLocale('fr', lcAll, true));
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('should not change LC_ALL when setting invalid locale', async () =>
       testLocale('asdfkl', lcAll, true)
     );
-    ifit(process.platform === 'linux')('should not change LC_ALL when --lang is not set', async () =>
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('should not change LC_ALL when --lang is not set', async () =>
       testLocale('', lcAll, true)
     );
   });
@@ -4265,12 +4265,12 @@ describe('font fallback', () => {
       expect(fonts[0].familyName).toBe('Arial');
     } else if (process.platform === 'darwin') {
       expect(fonts[0].familyName).toBe('Helvetica');
-    } else if (process.platform === 'linux') {
+    } else if (process.platform === 'linux' || process.platform === 'freebsd') {
       expect(fonts[0].familyName).toBe('DejaVu Sans');
     } // I think this depends on the distro? We don't specify a default.
   });
 
-  ifit(process.platform !== 'linux')('should fall back to Japanese font for sans-serif Japanese script', async () => {
+  ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('should fall back to Japanese font for sans-serif Japanese script', async () => {
     const html = `
     <html lang="ja-JP">
       <head>
@@ -4998,7 +4998,7 @@ describe('paste execCommand', { tags: ['serial'] }, ()
   });
 });
 
-ifdescribe(process.platform !== 'linux' || app.isUnityRunning())('navigator.setAppBadge/clearAppBadge', () => {
+ifdescribe((process.platform !== 'linux' && process.platform !== 'freebsd') || app.isUnityRunning())('navigator.setAppBadge/clearAppBadge', () => {
   let w: BrowserWindow;
 
   const expectedBadgeCount = 42;
