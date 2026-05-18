--- electron/spec/api-notification-dbus-spec.ts.orig	2026-05-08 13:54:01 UTC
+++ electron/spec/api-notification-dbus-spec.ts
@@ -21,7 +21,7 @@ const skip =
 const fixturesPath = path.join(__dirname, 'fixtures');
 
 const skip =
-  process.platform !== 'linux' ||
+  (process.platform !== 'linux' && process.platform !== 'freebsd') ||
   process.arch === 'ia32' ||
   process.arch.indexOf('arm') === 0 ||
   !process.env.DBUS_SESSION_BUS_ADDRESS;
