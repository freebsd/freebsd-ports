--- electron/spec/node-spec.js.orig	2019-09-16 09:55:33 UTC
+++ electron/spec/node-spec.js
@@ -157,7 +157,7 @@ describe('node feature', () => {
     })
 
     describe('child_process.exec', () => {
-      (process.platform === 'linux' ? it : it.skip)('allows executing a setuid binary from non-sandboxed renderer', () => {
+      (process.platform === 'linux' || process.platform === 'freebsd' ? it : it.skip)('allows executing a setuid binary from non-sandboxed renderer', () => {
         // Chrome uses prctl(2) to set the NO_NEW_PRIVILEGES flag on Linux (see
         // https://github.com/torvalds/linux/blob/40fde647cc/Documentation/userspace-api/no_new_privs.rst).
         // We disable this for unsandboxed processes, which the remote tests
