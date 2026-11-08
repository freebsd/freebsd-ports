--- electron/spec/api-browser-window-ignore-mouse-events.spec.ts.orig	2026-10-13 23:18:11 UTC
+++ electron/spec/api-browser-window-ignore-mouse-events.spec.ts
@@ -45,11 +45,11 @@ const hasRealInput =
 // Nothing can inject input into a Wayland compositor from a client, so only
 // X11 is covered on Linux.
 const hasRealInput =
-  process.platform === 'win32' || process.platform === 'darwin' || (process.platform === 'linux' && !isWayland);
+  process.platform === 'win32' || process.platform === 'darwin' || ((process.platform === 'linux' || process.platform === 'freebsd') && !isWayland);
 // { forward: true } is macOS and Windows only.
 const canForward = process.platform === 'win32' || process.platform === 'darwin';
 // Only these can ask the OS which window it hit tests at a point.
-const canHitTest = process.platform === 'win32' || process.platform === 'linux';
+const canHitTest = process.platform === 'win32' || process.platform === 'linux' || process.platform === 'freebsd';
 
 // #target turns orange while hovered. Element.matches(':hover') is not usable
 // here: it stays false while the (never focused) window is inactive even
