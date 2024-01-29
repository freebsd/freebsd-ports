--- electron/lib/browser/init.ts.orig	2023-10-20 08:29:17 UTC
+++ electron/lib/browser/init.ts
@@ -158,7 +158,7 @@ const mainStartupScript = packageJson.main || 'index.j
 const KNOWN_XDG_DESKTOP_VALUES = new Set(['Pantheon', 'Unity:Unity7', 'pop:GNOME']);
 
 function currentPlatformSupportsAppIndicator () {
-  if (process.platform !== 'linux') return false;
+  if (process.platform !== 'linux' && process.platform !== 'freebsd') return false;
   const currentDesktop = process.env.XDG_CURRENT_DESKTOP;
 
   if (!currentDesktop) return false;
