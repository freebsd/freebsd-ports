--- electron/spec/spellchecker.spec.ts.orig	2026-10-17 02:46:46 UTC
+++ electron/spec/spellchecker.spec.ts
@@ -92,7 +92,7 @@ ifdescribe(features.isBuiltinSpellCheckerEnabled())('s
       }, timeout);
 
       // Context menu test can not run on Windows or Linux (https://github.com/electron/electron/pull/48657 broke linux).
-      const shouldRun = process.platform !== 'win32' && process.platform !== 'linux';
+      const shouldRun = process.platform !== 'win32' && process.platform !== 'linux' && process.platform !== 'freebsd';
 
       ifit(shouldRun)('should detect correctly spelled words as correct', async () => {
         await w.webContents.executeJavaScript('document.body.querySelector("textarea").value = "typography"');
