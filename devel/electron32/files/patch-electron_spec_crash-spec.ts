--- electron/spec/crash-spec.ts.orig	2024-03-13 18:15:29 UTC
+++ electron/spec/crash-spec.ts
@@ -45,7 +45,7 @@ const shouldRunCase = (crashCase: string) => {
       if (process.platform === 'win32') {
         return process.arch !== 'ia32';
       } else {
-        return (process.platform !== 'linux' || (process.arch !== 'arm64' && process.arch !== 'arm'));
+        return ((process.platform !== 'linux' && process.platform !== 'freebsd') || (process.arch !== 'arm64' && process.arch !== 'arm'));
       }
     }
     default: {
