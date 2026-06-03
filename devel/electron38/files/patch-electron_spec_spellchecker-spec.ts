--- electron/spec/spellchecker-spec.ts.orig	2026-02-05 09:23:24 UTC
+++ electron/spec/spellchecker-spec.ts
@@ -89,7 +89,7 @@ ifdescribe(features.isBuiltinSpellCheckerEnabled())('s
       });
 
       // Context menu test can not run on Windows or Linux (https://github.com/electron/electron/pull/48657 broke linux).
-      const shouldRun = process.platform !== 'win32' && process.platform !== 'linux';
+      const shouldRun = process.platform !== 'win32' && process.platform !== 'linux' && process.platform !== 'freebsd';
 
       ifit(shouldRun)('should detect correctly spelled words as correct', async () => {
         await w.webContents.executeJavaScript('document.body.querySelector("textarea").value = "typography"');
