--- electron/spec-main/api-process-spec.ts.orig	2022-10-19 17:31:10.000000000 +0200
+++ electron/spec-main/api-process-spec.ts	2022-12-02 17:44:33.364867000 +0100
@@ -54,7 +54,7 @@ describe('process module', () => {
       it('resolves promise successfully with valid data', async () => {
         const memoryInfo = await w.webContents.executeJavaScript('process.getProcessMemoryInfo()');
         expect(memoryInfo).to.be.an('object');
-        if (process.platform === 'linux' || process.platform === 'win32') {
+        if (process.platform === 'linux' || process.platform === 'win32' || process.platform === 'freebsd') {
           expect(memoryInfo.residentSet).to.be.a('number').greaterThan(0);
         }
         expect(memoryInfo.private).to.be.a('number').greaterThan(0);
