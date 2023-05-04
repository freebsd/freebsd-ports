--- electron/spec/crash-spec.ts.orig	2023-02-21 16:55:58 UTC
+++ electron/spec/crash-spec.ts
@@ -42,7 +42,7 @@ const shouldRunCase = (crashCase: string) => {
     }
     // TODO(jkleinsc) fix this test on Linux on arm/arm64
     case 'js-execute-iframe': {
-      return (process.platform !== 'linux' || (process.arch !== 'arm64' && process.arch !== 'arm'));
+      return ((process.platform !== 'linux' && process.platform !== 'freebsd') || (process.arch !== 'arm64' && process.arch !== 'arm'));
     }
     default: {
       return true;
