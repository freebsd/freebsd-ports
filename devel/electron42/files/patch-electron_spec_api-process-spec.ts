--- electron/spec/api-process-spec.ts.orig	2026-07-28 14:50:45 UTC
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
@@ -55,7 +55,7 @@ describe('process module', () => {
         const systemMemoryInfo = await invoke(() => process.getSystemMemoryInfo());
         expect(systemMemoryInfo.free).to.be.a('number');
         expect(systemMemoryInfo.total).to.be.a('number');
-        if (process.platform === 'linux') {
+        if (process.platform === 'linux' || process.platform === 'freebsd') {
           expect(systemMemoryInfo.available).to.be.a('number').greaterThan(0);
         }
       });
