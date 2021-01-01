--- electron/lib/browser/init.js.orig	2019-05-23 00:31:34 UTC
+++ electron/lib/browser/init.js
@@ -167,7 +167,7 @@ const mainStartupScript = packageJson.main || 'index.j
 const KNOWN_XDG_DESKTOP_VALUES = ['Pantheon', 'Unity:Unity7', 'pop:GNOME']
 
 function currentPlatformSupportsAppIndicator () {
-  if (process.platform !== 'linux') return false
+  if (process.platform !== 'linux' && process.platform !== 'freebsd') return false
   const currentDesktop = process.env.XDG_CURRENT_DESKTOP
 
   if (!currentDesktop) return false
