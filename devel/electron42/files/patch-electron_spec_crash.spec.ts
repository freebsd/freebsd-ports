--- electron/spec/crash.spec.ts.orig	2026-10-14 00:49:29 UTC
+++ electron/spec/crash.spec.ts
@@ -54,7 +54,7 @@ const shouldRunCase = (crashCase: string) => {
       if (process.platform === 'win32') {
         return process.arch !== 'ia32';
       } else {
-        return process.platform !== 'linux' || (process.arch !== 'arm64' && process.arch !== 'arm');
+        return (process.platform !== 'linux' && process.platform !== 'freebsd') || (process.arch !== 'arm64' && process.arch !== 'arm');
       }
     }
     default: {
