--- electron/lib/browser/api/power-monitor.ts.orig	2021-01-25 12:15:22 UTC
+++ electron/lib/browser/api/power-monitor.ts
@@ -17,7 +17,7 @@ class PowerMonitor extends EventEmitter {
         const pm = createPowerMonitor();
         pm.emit = this.emit.bind(this);
 
-        if (process.platform === 'linux') {
+        if (process.platform === 'linux' || process.platform === 'freebsd') {
           // On Linux, we inhibit shutdown in order to give the app a chance to
           // decide whether or not it wants to prevent the shutdown. We don't
           // inhibit the shutdown event unless there's a listener for it. This
