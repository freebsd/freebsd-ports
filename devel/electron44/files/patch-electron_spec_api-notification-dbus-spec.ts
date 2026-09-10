--- electron/spec/api-notification-dbus-spec.ts.orig	2026-08-31 00:54:19 UTC
+++ electron/spec/api-notification-dbus-spec.ts
@@ -20,7 +20,7 @@ const fixturesPath = path.join(__dirname, 'fixtures');
 
 const fixturesPath = path.join(__dirname, 'fixtures');
 
-const skip = process.platform !== 'linux' || !process.env.DBUS_SESSION_BUS_ADDRESS;
+const skip = (process.platform !== 'linux' && process.platform !== 'freebsd') || !process.env.DBUS_SESSION_BUS_ADDRESS;
 
 ifdescribe(!skip)('Notification module (dbus)', () => {
   let mock: any, Notification: any, getCalls: any, emitSignal: any, reset: any;
