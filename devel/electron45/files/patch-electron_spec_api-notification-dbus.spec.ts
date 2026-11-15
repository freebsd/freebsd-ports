--- electron/spec/api-notification-dbus.spec.ts.orig	2026-09-29 23:27:57 UTC
+++ electron/spec/api-notification-dbus.spec.ts
@@ -23,7 +23,7 @@ const fixturesPath = path.join(import.meta.dirname, 'f
 
 const fixturesPath = path.join(import.meta.dirname, 'fixtures');
 
-const skip = process.platform !== 'linux' || !process.env.DBUS_SESSION_BUS_ADDRESS;
+const skip = (process.platform !== 'linux' && process.platform !== 'freebsd') || !process.env.DBUS_SESSION_BUS_ADDRESS;
 
 ifdescribe(!skip)('Notification module (dbus)', { tags: ['serial'] }, () => {
   let mock: any, Notification: any, getCalls: any, emitSignal: any, reset: any;
