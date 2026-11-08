--- electron/spec/lib/spec-helpers.ts.orig	2026-10-16 03:32:58 UTC
+++ electron/spec/lib/spec-helpers.ts
@@ -19,7 +19,7 @@ export const isWayland =
 export const ifdescribe = (condition: boolean) => (condition ? describe : describe.skip);
 
 export const isWayland =
-  process.platform === 'linux' &&
+  (process.platform === 'linux' || process.platform === 'freebsd') &&
   (process.env.XDG_SESSION_TYPE === 'wayland' ||
     !!process.env.WAYLAND_DISPLAY ||
     process.argv.includes('--ozone-platform=wayland'));
