--- electron/spec/api-power-monitor-spec.ts.orig	2026-05-07 20:19:20 UTC
+++ electron/spec/api-power-monitor-spec.ts
@@ -18,7 +18,7 @@ describe('powerMonitor', () => {
 describe('powerMonitor', () => {
   let logindMock: any, dbusMockPowerMonitor: any, getCalls: any, emitSignal: any, reset: any;
 
-  ifdescribe(process.platform === 'linux' && process.env.DBUS_SYSTEM_BUS_ADDRESS != null)(
+  ifdescribe((process.platform === 'linux' || process.platform === 'freebsd') && process.env.DBUS_SYSTEM_BUS_ADDRESS != null)(
     'when powerMonitor module is loaded with dbus mock',
     () => {
       before(async () => {
