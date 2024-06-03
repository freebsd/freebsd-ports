--- electron/lib/browser/init.ts.orig	2024-04-16 14:29:17 UTC
+++ electron/lib/browser/init.ts
@@ -161,7 +161,7 @@ function currentPlatformSupportsAppIndicator () {
 const KNOWN_XDG_DESKTOP_VALUES = new Set(['Pantheon', 'Unity:Unity7', 'pop:GNOME']);
 
 function currentPlatformSupportsAppIndicator () {
-  if (process.platform !== 'linux') return false;
+  if (process.platform !== 'linux' && process.platform !== 'freebsd') return false;
   const currentDesktop = process.env.XDG_CURRENT_DESKTOP;
 
   if (!currentDesktop) return false;
