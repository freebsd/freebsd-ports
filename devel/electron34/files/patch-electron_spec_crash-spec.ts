--- electron/spec/crash-spec.ts.orig	2025-03-26 14:46:58 UTC
+++ electron/spec/crash-spec.ts
@@ -52,7 +52,7 @@ const shouldRunCase = (crashCase: string) => {
       if (process.platform === 'win32') {
         return process.arch !== 'ia32';
       } else {
-        return (process.platform !== 'linux' || (process.arch !== 'arm64' && process.arch !== 'arm'));
+        return ((process.platform !== 'linux' && process.platform !== 'freebsd') || (process.arch !== 'arm64' && process.arch !== 'arm'));
       }
     }
     default: {
