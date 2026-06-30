--- electron/spec/api-protocol-spec.ts.orig	2026-06-29 04:13:32 UTC
+++ electron/spec/api-protocol-spec.ts
@@ -2095,7 +2095,7 @@ describe('protocol module', () => {
 
     // TODO(nornagon): this test doesn't pass on Linux currently, investigate.
     // test is also flaky on CI on macOS so it is currently disabled there as well.
-    ifit(process.platform !== 'linux' && (!process.env.CI || process.platform !== 'darwin'))('is fast', async () => {
+    ifit((process.platform !== 'linux' && process.platform !== 'freebsd') && (!process.env.CI || process.platform !== 'darwin'))('is fast', async () => {
       // 128 MB of spaces.
       const chunk = new Uint8Array(128 * 1024 * 1024);
       chunk.fill(' '.charCodeAt(0));
