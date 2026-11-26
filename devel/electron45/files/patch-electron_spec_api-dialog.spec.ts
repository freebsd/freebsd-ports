--- electron/spec/api-dialog.spec.ts.orig	2026-11-24 16:37:09 UTC
+++ electron/spec/api-dialog.spec.ts
@@ -1067,7 +1067,7 @@ describe('dialog module', () => {
   // FileChooser that script/dbus_mock.py hosts on the fake session bus. The
   // mock records each request and auto-cancels the dialog.
   ifdescribe(
-    process.platform === 'linux' &&
+    (process.platform === 'linux' || process.platform === 'freebsd') &&
       process.arch !== 'ia32' &&
       !process.arch.startsWith('arm') &&
       !!process.env.DBUS_SESSION_BUS_ADDRESS
