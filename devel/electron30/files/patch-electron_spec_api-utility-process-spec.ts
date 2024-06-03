--- electron/spec/api-utility-process-spec.ts.orig	2024-01-23 19:02:02 UTC
+++ electron/spec/api-utility-process-spec.ts
@@ -400,7 +400,7 @@ describe('utilityProcess module', () => {
       await closeWindow(w);
     });
 
-    ifit(process.platform === 'linux')('allows executing a setuid binary with child_process', async () => {
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('allows executing a setuid binary with child_process', async () => {
       const child = utilityProcess.fork(path.join(fixturesPath, 'suid.js'));
       await once(child, 'spawn');
       const [data] = await once(child, 'message');
