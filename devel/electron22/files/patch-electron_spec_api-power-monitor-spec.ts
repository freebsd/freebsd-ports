--- electron/spec/api-power-monitor-spec.ts.orig	2022-10-19 17:31:10.000000000 +0200
+++ electron/spec/api-power-monitor-spec.ts	2022-12-02 17:49:13.141645000 +0100
@@ -14,7 +14,7 @@ describe('powerMonitor', () => {
 describe('powerMonitor', () => {
   let logindMock: any, dbusMockPowerMonitor: any, getCalls: any, emitSignal: any, reset: any;
 
-  ifdescribe(process.platform === 'linux' && process.env.DBUS_SYSTEM_BUS_ADDRESS != null)('when powerMonitor module is loaded with dbus mock', () => {
+  ifdescribe((process.platform === 'linux' || process.platform === 'freebsd') && process.env.DBUS_SYSTEM_BUS_ADDRESS != null)('when powerMonitor module is loaded with dbus mock', () => {
     before(async () => {
       const systemBus = dbus.systemBus();
       const loginService = systemBus.getService('org.freedesktop.login1');
