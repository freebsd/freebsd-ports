--- electron/spec/node-spec.ts.orig	2024-10-09 13:53:06 UTC
+++ electron/spec/node-spec.ts
@@ -148,7 +148,7 @@ describe('node feature', () => {
     });
 
     describe('child_process.exec', () => {
-      ifit(process.platform === 'linux')('allows executing a setuid binary from non-sandboxed renderer', async () => {
+      ifit(process.platform === 'linux' || process.platform === 'freebsd')('allows executing a setuid binary from non-sandboxed renderer', async () => {
         // Chrome uses prctl(2) to set the NO_NEW_PRIVILEGES flag on Linux (see
         // https://github.com/torvalds/linux/blob/40fde647cc/Documentation/userspace-api/no_new_privs.rst).
         // We disable this for unsandboxed processes, which the renderer tests
