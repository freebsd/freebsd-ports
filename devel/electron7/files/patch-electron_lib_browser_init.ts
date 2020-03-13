--- electron/lib/browser/init.ts.orig	2020-02-20 17:38:02 UTC
+++ electron/lib/browser/init.ts
@@ -165,7 +165,7 @@ const mainStartupScript = packageJson.main || 'index.j
 const KNOWN_XDG_DESKTOP_VALUES = ['Pantheon', 'Unity:Unity7', 'pop:GNOME']
 
 function currentPlatformSupportsAppIndicator () {
-  if (process.platform !== 'linux') return false
+  if (process.platform !== 'linux' && process.platform !== 'freebsd') return false
   const currentDesktop = process.env.XDG_CURRENT_DESKTOP
 
   if (!currentDesktop) return false
