--- electron/spec/api-process-spec.ts.orig	2026-09-08 07:41:45 UTC
+++ electron/spec/api-process-spec.ts
@@ -43,7 +43,7 @@ describe('process module', () => {
       it('resolves promise successfully with valid data', async () => {
         const memoryInfo = await invoke(() => process.getProcessMemoryInfo());
         expect(memoryInfo).to.be.an('object');
-        if (process.platform === 'linux' || process.platform === 'win32') {
+        if (process.platform === 'linux' || process.platform === 'win32' || process.platform === 'freebsd') {
           expect(memoryInfo.residentSet).to.be.a('number').greaterThan(0);
         }
         expect(memoryInfo.private).to.be.a('number').greaterThan(0);
@@ -57,7 +57,7 @@ describe('process module', () => {
         const systemMemoryInfo = await invoke(() => process.getSystemMemoryInfo());
         expect(systemMemoryInfo.free).to.be.a('number');
         expect(systemMemoryInfo.total).to.be.a('number');
-        if (process.platform === 'linux') {
+        if (process.platform === 'linux' || process.platform === 'freebsd') {
           expect(systemMemoryInfo.available).to.be.a('number').greaterThan(0);
         }
       });
@@ -136,7 +136,7 @@ describe('process module', () => {
     generateSpecs((fn, ...args) => fn(...args));
   });
 
-  ifdescribe(process.platform === 'linux')('process.env', () => {
+  ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')('process.env', () => {
     it('can add variables while another thread reads the environment', async () => {
       const fixture = path.join(__dirname, 'fixtures', 'api', 'environ-write-race.js');
       const child = cp.spawn(process.execPath, [fixture], { stdio: ['ignore', 'pipe', 'inherit'] });
