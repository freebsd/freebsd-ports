--- electron/spec/lib/spec-helpers.ts.orig	2026-09-29 23:27:57 UTC
+++ electron/spec/lib/spec-helpers.ts
@@ -29,7 +29,7 @@ export const isWayland =
 export const ifdescribe = (condition: boolean) => (condition ? describe : addOnly<SuiteFunction>(describe.skip));
 
 export const isWayland =
-  process.platform === 'linux' &&
+  (process.platform === 'linux' || process.platform === 'freebsd') &&
   (process.env.XDG_SESSION_TYPE === 'wayland' ||
     !!process.env.WAYLAND_DISPLAY ||
     process.argv.includes('--ozone-platform=wayland'));
