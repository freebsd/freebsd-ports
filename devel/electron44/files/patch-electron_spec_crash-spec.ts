--- electron/spec/crash-spec.ts.orig	2026-09-15 22:52:01 UTC
+++ electron/spec/crash-spec.ts
@@ -47,7 +47,7 @@ const shouldRunCase = (crashCase: string) => {
   switch (crashCase) {
     // TODO(jkleinsc) fix this test on Linux on arm64
     case 'js-execute-iframe': {
-      return process.platform !== 'linux' || process.arch !== 'arm64';
+      return (process.platform !== 'linux' && process.platform !== 'freebsd') || process.arch !== 'arm64';
     }
     default: {
       return true;
