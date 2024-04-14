--- electron/spec/api-process-spec.ts.orig	2023-01-24 16:58:16 UTC
+++ electron/spec/api-process-spec.ts
@@ -54,7 +54,7 @@ describe('process module', () => {
       it('resolves promise successfully with valid data', async () => {
         const memoryInfo = await w.webContents.executeJavaScript('process.getProcessMemoryInfo()');
         expect(memoryInfo).to.be.an('object');
-        if (process.platform === 'linux' || process.platform === 'win32') {
+        if (process.platform === 'linux' || process.platform === 'win32' || process.platform === 'freebsd') {
           expect(memoryInfo.residentSet).to.be.a('number').greaterThan(0);
         }
         expect(memoryInfo.private).to.be.a('number').greaterThan(0);
@@ -164,7 +164,7 @@ describe('process module', () => {
       it('resolves promise successfully with valid data', async () => {
         const memoryInfo = await process.getProcessMemoryInfo();
         expect(memoryInfo).to.be.an('object');
-        if (process.platform === 'linux' || process.platform === 'win32') {
+        if (process.platform === 'linux' || process.platform === 'win32' || process.platform === 'freebsd') {
           expect(memoryInfo.residentSet).to.be.a('number').greaterThan(0);
         }
         expect(memoryInfo.private).to.be.a('number').greaterThan(0);
