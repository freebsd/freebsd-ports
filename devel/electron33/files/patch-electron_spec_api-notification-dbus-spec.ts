--- electron/spec/api-notification-dbus-spec.ts.orig	2024-10-09 13:53:06 UTC
+++ electron/spec/api-notification-dbus-spec.ts
@@ -19,7 +19,7 @@ const fixturesPath = path.join(__dirname, 'fixtures');
 
 const fixturesPath = path.join(__dirname, 'fixtures');
 
-const skip = process.platform !== 'linux' ||
+const skip = (process.platform !== 'linux' && process.platform !== 'freebsd') ||
              process.arch === 'ia32' ||
              process.arch.indexOf('arm') === 0 ||
              !process.env.DBUS_SESSION_BUS_ADDRESS;
