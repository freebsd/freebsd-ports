--- electron/spec-main/crash-spec.ts.orig	2023-01-13 05:28:08 UTC
+++ electron/spec-main/crash-spec.ts
@@ -39,7 +39,7 @@ const shouldRunCase = (crashCase: string) => {
     }
     // TODO(jkleinsc) fix this test on Linux on arm/arm64
     case 'js-execute-iframe': {
-      return (process.platform !== 'linux' || (process.arch !== 'arm64' && process.arch !== 'arm'));
+      return ((process.platform !== 'linux' && process.platform !== 'freebsd') || (process.arch !== 'arm64' && process.arch !== 'arm'));
     }
     default: {
       return true;
