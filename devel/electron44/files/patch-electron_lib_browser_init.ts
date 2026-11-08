--- electron/lib/browser/init.ts.orig	2026-09-17 00:59:07 UTC
+++ electron/lib/browser/init.ts
@@ -132,7 +132,7 @@ if (packageJson.productName != null) {
   app.name = `${packageJson.name}`.trim();
 }
 
-if (process.platform === 'linux') {
+if (process.platform === 'linux' || process.platform === 'freebsd') {
   const { defaultDesktopName } =
     require('@electron/internal/browser/desktop-name') as typeof import('@electron/internal/browser/desktop-name');
   app.setDesktopName(packageJson.desktopName || defaultDesktopName(app.name));
