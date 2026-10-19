--- electron/spec/api-utility-process.spec.ts.orig	2026-10-17 02:46:46 UTC
+++ electron/spec/api-utility-process.spec.ts
@@ -649,7 +649,7 @@ describe('utilityProcess module', () => {
       expect(output).toContain(result);
     });
 
-    ifit(process.platform !== 'linux')('can access exposed main process modules from the utility process', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('can access exposed main process modules from the utility process', async () => {
       const message = 'Message from utility process';
       const child = utilityProcess.fork(path.join(fixturesPath, 'expose-main-process-module.js'));
       await once(child, 'spawn');
@@ -686,7 +686,7 @@ describe('utilityProcess module', () => {
       await closeWindow(w);
     });
 
-    ifit(process.platform === 'linux')('allows executing a setuid binary with child_process', async () => {
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('allows executing a setuid binary with child_process', async () => {
       const child = utilityProcess.fork(path.join(fixturesPath, 'suid.js'));
       await once(child, 'spawn');
       const [data] = await once(child, 'message');
