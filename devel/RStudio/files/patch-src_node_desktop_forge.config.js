- Configure electron-forge to use pre-downloaded Electron zip from electron37 package

--- src/node/desktop/forge.config.js.orig	2025-12-01 04:21:27 UTC
+++ src/node/desktop/forge.config.js
@@ -58,6 +58,8 @@ const config = {
 
   // https://electron.github.io/electron-packager/main/interfaces/electronpackager.options.html 
   packagerConfig: {
+    platform: 'linux',
+    electronZipDir: process.env.ELECTRON_ZIP_DIR || '/usr/local/share/electron37',
     icon: './resources/icons/RStudio',
     appBundleId: 'com.rstudio.desktop',
     appCopyright: `Copyright (C) ${new Date().getFullYear()} by Posit Software, PBC`,
