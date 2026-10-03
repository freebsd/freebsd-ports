--- electron/spec/api-power-monitor.spec.ts.orig	2026-09-29 23:27:57 UTC
+++ electron/spec/api-power-monitor.spec.ts
@@ -21,7 +21,7 @@ describe('powerMonitor', { tags: ['serial'] }, () => {
 describe('powerMonitor', { tags: ['serial'] }, () => {
   let logindMock: any, dbusMockPowerMonitor: any, getCalls: any, emitSignal: any, reset: any;
 
-  ifdescribe(process.platform === 'linux' && process.env.DBUS_SYSTEM_BUS_ADDRESS != null)(
+  ifdescribe((process.platform === 'linux' || process.platform === 'freebsd') && process.env.DBUS_SYSTEM_BUS_ADDRESS != null)(
     'when powerMonitor module is loaded with dbus mock',
     () => {
       before(async () => {
