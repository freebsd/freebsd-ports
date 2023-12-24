--- electron/spec/api-protocol-spec.ts.orig	2023-12-21 18:00:06 UTC
+++ electron/spec/api-protocol-spec.ts
@@ -1548,7 +1548,7 @@ describe('protocol module', () => {
     });
 
     // TODO(nornagon): this test doesn't pass on Linux currently, investigate.
-    ifit(process.platform !== 'linux')('is fast', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('is fast', async () => {
       // 128 MB of spaces.
       const chunk = new Uint8Array(128 * 1024 * 1024);
       chunk.fill(' '.charCodeAt(0));
