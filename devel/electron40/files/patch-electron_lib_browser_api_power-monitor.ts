--- electron/lib/browser/api/power-monitor.ts.orig	2026-03-17 08:46:36 UTC
+++ electron/lib/browser/api/power-monitor.ts
@@ -23,7 +23,7 @@ class PowerMonitor extends EventEmitter implements Ele
       pm = createPowerMonitor();
       pm.emit = this.emit.bind(this);
 
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // On Linux, we inhibit shutdown in order to give the app a chance to
         // decide whether or not it wants to prevent the shutdown. We don't
         // inhibit the shutdown event unless there's a listener for it. This
