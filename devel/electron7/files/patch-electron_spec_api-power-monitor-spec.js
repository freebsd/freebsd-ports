--- electron/spec/api-power-monitor-spec.js.orig	2020-03-24 05:00:48 UTC
+++ electron/spec/api-power-monitor-spec.js
@@ -14,7 +14,7 @@ const Promise = require('bluebird');
 const { expect } = chai;
 chai.use(dirtyChai);
 
-const skip = process.platform !== 'linux' || !process.env.DBUS_SYSTEM_BUS_ADDRESS;
+const skip = (process.platform !== 'linux' && process.platform !== 'freebsd') || !process.env.DBUS_SYSTEM_BUS_ADDRESS;
 
 describe('powerMonitor', () => {
   let logindMock, dbusMockPowerMonitor, getCalls, emitSignal, reset;
