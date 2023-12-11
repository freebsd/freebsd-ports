--- electron/spec/node-spec.ts.orig	2023-10-20 08:29:17 UTC
+++ electron/spec/node-spec.ts
@@ -137,7 +137,7 @@ describe('node feature', () => {
     });
 
     describe('child_process.exec', () => {
-      ifit(process.platform === 'linux')('allows executing a setuid binary from non-sandboxed renderer', async () => {
+      ifit(process.platform === 'linux' || process.platform === 'freebsd')('allows executing a setuid binary from non-sandboxed renderer', async () => {
         // Chrome uses prctl(2) to set the NO_NEW_PRIVILEGES flag on Linux (see
         // https://github.com/torvalds/linux/blob/40fde647cc/Documentation/userspace-api/no_new_privs.rst).
         // We disable this for unsandboxed processes, which the renderer tests
