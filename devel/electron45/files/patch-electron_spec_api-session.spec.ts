--- electron/spec/api-session.spec.ts.orig	2026-11-26 06:44:57 UTC
+++ electron/spec/api-session.spec.ts
@@ -1896,7 +1896,7 @@ describe('session module', { retry: 0 }, () => {
     // hosts on the fake session bus. The mock answers with the path queued
     // through QueueResponse, or cancels when nothing is queued.
     ifdescribe(
-      process.platform === 'linux' &&
+      (process.platform === 'linux' || process.platform === 'freebsd') &&
         process.arch !== 'ia32' &&
         !process.arch.startsWith('arm') &&
         !!process.env.DBUS_SESSION_BUS_ADDRESS
