--- electron/spec/crash-spec.ts.orig	2026-08-31 00:54:19 UTC
+++ electron/spec/crash-spec.ts
@@ -46,7 +46,7 @@ const shouldRunCase = (crashCase: string) => {
   switch (crashCase) {
     // TODO(jkleinsc) fix this test on Linux on arm64
     case 'js-execute-iframe': {
-      return process.platform !== 'linux' || process.arch !== 'arm64';
+      return (process.platform !== 'linux' && process.platform !== 'freebsd') || process.arch !== 'arm64';
     }
     default: {
       return true;
