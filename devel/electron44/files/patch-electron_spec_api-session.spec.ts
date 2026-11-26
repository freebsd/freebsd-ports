--- electron/spec/api-session.spec.ts.orig	2026-11-26 03:39:59 UTC
+++ electron/spec/api-session.spec.ts
@@ -1897,7 +1897,7 @@ describe('session module', () => {
     // hosts on the fake session bus. The mock answers with the path queued
     // through QueueResponse, or cancels when nothing is queued.
     ifdescribe(
-      process.platform === 'linux' &&
+      (process.platform === 'linux' || process.platform === 'freebsd') &&
         process.arch !== 'ia32' &&
         !process.arch.startsWith('arm') &&
         !!process.env.DBUS_SESSION_BUS_ADDRESS
