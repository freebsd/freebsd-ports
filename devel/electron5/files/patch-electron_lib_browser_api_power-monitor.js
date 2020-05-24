--- electron/lib/browser/api/power-monitor.js.orig	2019-05-23 04:05:25 UTC
+++ electron/lib/browser/api/power-monitor.js
@@ -8,7 +8,7 @@ Object.setPrototypeOf(PowerMonitor.prototype, EventEmi
 EventEmitter.call(powerMonitor)
 
 // On Linux we need to call blockShutdown() to subscribe to shutdown event.
-if (process.platform === 'linux') {
+if (process.platform === 'linux' || process.platform === 'freebsd') {
   powerMonitor.on('newListener', (event) => {
     if (event === 'shutdown' && powerMonitor.listenerCount('shutdown') === 0) {
       powerMonitor.blockShutdown()
