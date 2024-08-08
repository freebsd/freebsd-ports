--- electron/spec/api-process-spec.ts.orig	2024-04-16 14:29:17 UTC
+++ electron/spec/api-process-spec.ts
@@ -42,7 +42,7 @@ describe('process module', () => {
       it('resolves promise successfully with valid data', async () => {
         const memoryInfo = await w.webContents.executeJavaScript('process.getProcessMemoryInfo()');
         expect(memoryInfo).to.be.an('object');
-        if (process.platform === 'linux' || process.platform === 'win32') {
+        if (process.platform === 'linux' || process.platform === 'win32' || process.platform === 'freebsd') {
           expect(memoryInfo.residentSet).to.be.a('number').greaterThan(0);
         }
         expect(memoryInfo.private).to.be.a('number').greaterThan(0);
@@ -140,7 +140,7 @@ describe('process module', () => {
       it('resolves promise successfully with valid data', async () => {
         const memoryInfo = await process.getProcessMemoryInfo();
         expect(memoryInfo).to.be.an('object');
-        if (process.platform === 'linux' || process.platform === 'win32') {
+        if (process.platform === 'linux' || process.platform === 'win32' || process.platform === 'freebsd') {
           expect(memoryInfo.residentSet).to.be.a('number').greaterThan(0);
         }
         expect(memoryInfo.private).to.be.a('number').greaterThan(0);
