--- electron/spec/api-dialog.spec.ts.orig	2026-09-29 23:27:57 UTC
+++ electron/spec/api-dialog.spec.ts
@@ -1046,7 +1046,7 @@ describe('dialog module', () => {
   // FileChooser that script/dbus_mock.py hosts on the fake session bus. The
   // mock records each request and auto-cancels the dialog.
   ifdescribe(
-    process.platform === 'linux' &&
+    (process.platform === 'linux' || process.platform === 'freebsd') &&
       process.arch !== 'ia32' &&
       !process.arch.startsWith('arm') &&
       !!process.env.DBUS_SESSION_BUS_ADDRESS
