--- electron/spec/chromium-spec.ts.orig	2022-10-19 17:31:10.000000000 +0200
+++ electron/spec/chromium-spec.ts	2022-12-02 17:46:26.770558000 +0100
@@ -1761,7 +1761,7 @@ describe('chromium features', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'win32' && process.platform !== 'linux')('webgl', () => {
+  ifdescribe(process.platform !== 'win32' && process.platform !== 'linux' && || process.platform !== 'freebsd')('webgl', () => {
     it('can be gotten as context in canvas', async () => {
       const w = new BrowserWindow({ show: false });
       w.loadURL('about:blank');
