--- electron/lib/browser/api/power-monitor.ts.orig	2023-05-03 13:27:52 UTC
+++ electron/lib/browser/api/power-monitor.ts
@@ -19,7 +19,7 @@ class PowerMonitor extends EventEmitter {
         const pm = createPowerMonitor();
         pm.emit = this.emit.bind(this);
 
-        if (process.platform === 'linux') {
+        if (process.platform === 'linux' || process.platform === 'freebsd') {
           // On Linux, we inhibit shutdown in order to give the app a chance to
           // decide whether or not it wants to prevent the shutdown. We don't
           // inhibit the shutdown event unless there's a listener for it. This
