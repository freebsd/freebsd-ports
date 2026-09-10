--- electron/spec/api-crash-reporter-spec.ts.orig	2026-08-31 00:54:19 UTC
+++ electron/spec/api-crash-reporter-spec.ts
@@ -180,7 +180,7 @@ ifdescribe(!process.mas && !process.env.DISABLE_CRASH_
 
     // Ensures that passing in crashpadHandlerPID flag for Linx child processes
     // does not affect child process args.
-    ifit(process.platform === 'linux')('ensure linux child process args are not modified', async () => {
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('ensure linux child process args are not modified', async () => {
       const { port, waitForCrash } = await startServer();
       let exitCode: number | null = null;
       const appPath = path.join(__dirname, 'fixtures', 'apps', 'crash');
@@ -641,7 +641,7 @@ ifdescribe(!process.mas && !process.env.DISABLE_CRASH_
     }
 
     const processList =
-      process.platform === 'linux'
+      process.platform === 'linux' || process.platform === 'freebsd'
         ? ['main', 'renderer', 'sandboxed-renderer']
         : ['main', 'renderer', 'sandboxed-renderer', 'node'];
     for (const crashingProcess of processList) {
@@ -658,7 +658,7 @@ ifdescribe(!process.mas && !process.env.DISABLE_CRASH_
             return app.getPath('crashDumps');
           });
           let reportsDir = crashesDir;
-          if (process.platform === 'darwin' || process.platform === 'linux') {
+          if (process.platform === 'darwin' || process.platform === 'linux' || process.platform === 'freebsd') {
             reportsDir = path.join(crashesDir, 'completed');
           } else if (process.platform === 'win32') {
             reportsDir = path.join(crashesDir, 'reports');
@@ -686,7 +686,7 @@ ifdescribe(!process.mas && !process.env.DISABLE_CRASH_
           expect(remoteCrashesDir).to.equal(crashesDir);
 
           let reportsDir = crashesDir;
-          if (process.platform === 'darwin' || process.platform === 'linux') {
+          if (process.platform === 'darwin' || process.platform === 'linux' || process.platform === 'freebsd') {
             reportsDir = path.join(crashesDir, 'completed');
           } else if (process.platform === 'win32') {
             reportsDir = path.join(crashesDir, 'reports');
