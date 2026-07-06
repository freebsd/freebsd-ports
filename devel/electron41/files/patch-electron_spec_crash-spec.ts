--- electron/spec/crash-spec.ts.orig	2026-07-03 02:01:22 UTC
+++ electron/spec/crash-spec.ts
@@ -53,7 +53,7 @@ const shouldRunCase = (crashCase: string) => {
       if (process.platform === 'win32') {
         return process.arch !== 'ia32';
       } else {
-        return process.platform !== 'linux' || (process.arch !== 'arm64' && process.arch !== 'arm');
+        return (process.platform !== 'linux' && process.platform !== 'freebsd') || (process.arch !== 'arm64' && process.arch !== 'arm');
       }
     }
     default: {
