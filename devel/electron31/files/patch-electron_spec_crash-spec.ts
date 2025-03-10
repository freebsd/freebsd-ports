--- electron/spec/crash-spec.ts.orig	2024-10-09 13:53:12 UTC
+++ electron/spec/crash-spec.ts
@@ -47,7 +47,7 @@ const shouldRunCase = (crashCase: string) => {
       if (process.platform === 'win32') {
         return process.arch !== 'ia32';
       } else {
-        return (process.platform !== 'linux' || (process.arch !== 'arm64' && process.arch !== 'arm'));
+        return ((process.platform !== 'linux' && process.platform !== 'freebsd') || (process.arch !== 'arm64' && process.arch !== 'arm'));
       }
     }
     default: {
