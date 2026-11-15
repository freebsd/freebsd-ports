--- electron/spec/api-protocol.spec.ts.orig	2026-10-26 21:12:45 UTC
+++ electron/spec/api-protocol.spec.ts
@@ -2980,7 +2980,7 @@ describe('protocol module', () => {
       expect(relayedVsDirect, details).toBeLessThan(5);
       // Relaying should beat pumping the body through JS on the same machine
       // (about 0.5x on Linux). Only Linux has been measured so far.
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         expect(relayedVsPiped, details).toBeLessThan(0.8);
       }
     });
