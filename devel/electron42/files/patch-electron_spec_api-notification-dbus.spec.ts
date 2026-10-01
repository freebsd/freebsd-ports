--- electron/spec/api-notification-dbus.spec.ts.orig	2026-09-30 08:48:04 UTC
+++ electron/spec/api-notification-dbus.spec.ts
@@ -24,7 +24,7 @@ const skip =
 const fixturesPath = path.join(import.meta.dirname, 'fixtures');
 
 const skip =
-  process.platform !== 'linux' ||
+  (process.platform !== 'linux' && process.platform !== 'freebsd') ||
   process.arch === 'ia32' ||
   process.arch.indexOf('arm') === 0 ||
   !process.env.DBUS_SESSION_BUS_ADDRESS;
