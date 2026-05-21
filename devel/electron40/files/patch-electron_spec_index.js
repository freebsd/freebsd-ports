--- electron/spec/index.js.orig	2026-05-21 06:44:58 UTC
+++ electron/spec/index.js
@@ -176,7 +176,7 @@ async function killOrphanedElectronProcesses(suiteName
         try {
           // On Linux, skip any process that is a descendant of the current
           // Electron instance (GPU, renderer, zygote, crashpad, etc.).
-          if (process.platform === 'linux' && isDescendantOfCurrentProcess(pid)) continue;
+          if ((process.platform === 'linux' || process.platform === 'freebsd') && isDescendantOfCurrentProcess(pid)) continue;
           process.kill(pid, 'SIGKILL');
           killed++;
         } catch {
