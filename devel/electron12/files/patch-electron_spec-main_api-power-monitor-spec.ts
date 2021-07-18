--- electron/spec-main/api-power-monitor-spec.ts.orig	2021-01-22 23:55:24 UTC
+++ electron/spec-main/api-power-monitor-spec.ts
@@ -15,7 +15,7 @@ describe('powerMonitor', () => {
   let logindMock: any, dbusMockPowerMonitor: any, getCalls: any, emitSignal: any, reset: any;
 
   // TODO(deepak1556): Enable on arm64 after upgrade, it crashes at the moment.
-  ifdescribe(process.platform === 'linux' && process.arch !== 'arm64' && process.env.DBUS_SYSTEM_BUS_ADDRESS != null)('when powerMonitor module is loaded with dbus mock', () => {
+  ifdescribe((process.platform === 'linux' || process.platform === 'freebsd') && process.arch !== 'arm64' && process.env.DBUS_SYSTEM_BUS_ADDRESS != null)('when powerMonitor module is loaded with dbus mock', () => {
     before(async () => {
       const systemBus = dbus.systemBus();
       const loginService = systemBus.getService('org.freedesktop.login1');
