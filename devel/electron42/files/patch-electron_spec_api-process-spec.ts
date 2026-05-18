--- electron/spec/api-process-spec.ts.orig	2026-05-07 20:19:20 UTC
+++ electron/spec/api-process-spec.ts
@@ -41,7 +41,7 @@ describe('process module', () => {
       it('resolves promise successfully with valid data', async () => {
         const memoryInfo = await invoke(() => process.getProcessMemoryInfo());
         expect(memoryInfo).to.be.an('object');
-        if (process.platform === 'linux' || process.platform === 'win32') {
+        if (process.platform === 'linux' || process.platform === 'win32' || process.platform === 'freebsd') {
           expect(memoryInfo.residentSet).to.be.a('number').greaterThan(0);
         }
         expect(memoryInfo.private).to.be.a('number').greaterThan(0);
